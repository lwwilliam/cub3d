/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:59:39 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/03 17:14:10 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_middle(t_map *map, int h, int w)
{
	if (map->map[h + 1][w] != ' ' && map->map[h + 1][w] != '1')
		return (1);
	if (map->map[h - 1][w] != ' ' && map->map[h - 1][w] != '1')
		return (1);
	if (map->map[h][w + 1] != ' ' && map->map[h][w + 1] != '1')
		return (1);
	if (map->map[h][w - 1] != ' ' && map->map[h][w - 1] != '1')
		return (1);
	return (0);
}

static int	wall_side(t_map *map)
{
	int		y;
	int		x;
	char	*tmp;

	y = -1;
	x = -1;
	while (map->map[++y])
	{
		x = 0;
		while (map->map[y][x++])
		{
			if (x != 0 && y != 0 && x != ft_strlen(map->map[y])
				&& y != map->map_height - 1)
			{
				tmp = ft_strtrim(map->map[y], " ");
				if (tmp[0] != '1' && tmp[ft_strlen(tmp)] != '1')
					return (1);
				free(tmp);
				if (map->map[y][x] == ' ')
					if (check_middle(map, y, x) == 1)
						return (1);
			}
		}
	}
	return (0);
}

static void	wall(t_map *map, char *line, int current_width)
{
	int	x;

	x = 0;
	if (current_width == 0 || current_width == map->map_height)
	{
		while (line[x])
		{
			if (line[x] != '1' && line[x] != ' ')
				exit_err(map, "Error\nMap not enclosed\n", 1);
			x++;
		}
	}
	if (wall_side(map) == 1)
		exit_err(map, "Error\nMap not enclosed\n", 1);
}

static void	valid_character(t_map *map, char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ')
		exit_err(map, "Error\nInvalid character in map\n", 1);
	if (!map->north_texture[0] || !map->south_texture[0]
		|| !map->west_texture[0] || !map->east_texture[0]
		|| !map->floor_colour[0] || !map->ceilling_colour[0])
		exit_err(map, "Error\nMissing Identifier\n", 1);
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
		wall(map, map->map[y], y);
		while (map->map[y][x])
		{
			valid_character(map, map->map[y][x]);
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'E' || map->map[y][x] == 'W')
			{
				map->map_posx = x;
				map->map_posy = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}
