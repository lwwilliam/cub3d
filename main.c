/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:53:15 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/03 17:18:27 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_window(t_cub *cub, t_map *map)
{
	mlx_destroy_window(cub->mlx, cub->win);
	exit_err(map, "Error\nFile failed to open\n", 1);
}

int	win_init(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, MAP_WIDTH, MAP_HEIGHT, "cub3d");
	return (0);
}

int	map_init(t_map *map, char *file)
{
	init_map_vars(map);
	map_size(map, file);
	map_assign(map, file);
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
		exit_err(&map, "Error\nInvalid Filename\n", 0);
	if (map_init(&map, av[1]) == 1)
		return (1);
	game(&map, &cub);
	win_init(&cub);
	mlx_hook(cub.win, 17, 0, close_window, &cub);
	mlx_hook(cub.win, 2, 1L<<0, key_press, map);
	mlx_key_hook(cub.win, key_release, &cub);
	mlx_loop_hook(cub.mlx, create_map, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

void	exit_err(t_map *map, char *message, int code)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\033[0m", 2);
	if (code == 1)
		free_funct(map->map);
	exit(0);
}