/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:53:15 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:37 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	if (ac != 2)
		return (1);
	if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		ft_putstr_fd("\033[0;31mError!\nInvalid File\033[0m\n", 2);
	if (map_init(&map, av[1]) == 1)
		return (1);
	game(&map);
	return (0);
}
