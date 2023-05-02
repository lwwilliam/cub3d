/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:53:15 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/02 16:43:13 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_button(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	write(1, "=================================\n", 34);
	write(0, "Exit\n", 5);
	write(1, "=================================\n", 34);
	exit(0);
}

int	win_init(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, MAP_WIDTH, MAP_HEIGHT, "cub3d");
	return (0);
}

int	map_init(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\033[0;31mError!\nInvalid File\033[0m\n", 2);
		return (1);
	}
	if (map_size(map, fd) == 1)
		return (1);
	fd = open(file, O_RDONLY);
	map->map_height = 0;
	if (map_assign(map, fd) == 1)
	{
		free_funct(map->map);
		return (1);
	}
	if (map_check(map) == 1)
	{
		free_funct(map->map);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_cub	cub;

	if (ac != 2)
		return (1);
	if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		ft_putstr_fd("\033[0;31mError!\nInvalid File\033[0m\n", 2);
	if (map_init(&map, av[1]) == 1)
		return (1);
	game(&map, &cub);
	win_init(&cub);
	mlx_hook(cub.win, 17, 0, exit_button, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
