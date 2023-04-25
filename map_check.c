/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:59:39 by lwilliam          #+#    #+#             */
/*   Updated: 2023/04/25 20:47:48 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '1' && line[x] != ' ')
		{
			ft_putstr_fd("\033[0;31mError!\nMap \
is not closed by walls\033[0m\n", 2);
			return (1);
		}
		x++;
	}
	return (0);
}

int	valid_character(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ')
	{
		ft_putstr_fd("\033[0;31mError!\nMap contains \
invalid character\033[0m\n", 2);
		return (1);
	}
	return (0);
}

int	map_check(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->map[y])
	{
		x = 0;
		// if (y == 0 || y == map->map_height)
		if (wall(map->map[y]) == 1)
			return (1);
		while (map->map[y][x])
		{
			if (valid_character(map->map[y][x]) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
