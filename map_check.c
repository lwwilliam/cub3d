/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:59:39 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/29 17:19:58 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_middle(t_master *m, int h, int w)
{
	if (m->map.grid[h + 1][w] != ' ' && m->map.grid[h + 1][w] != '1')
		return (1);
	if (m->map.grid[h - 1][w] != ' ' && m->map.grid[h - 1][w] != '1')
		return (1);
	if (m->map.grid[h][w + 1] != ' ' && m->map.grid[h][w + 1] != '1')
		return (1);
	if (m->map.grid[h][w - 1] != ' ' && m->map.grid[h][w - 1] != '1')
		return (1);
	return (0);
}

static int	wall_side(t_master *m)
{
	int		y;
	int		x;
	char	*tmp;

	y = -1;
	x = -1;
	while (m->map.grid[++y])
	{
		x = 0;
		while (m->map.grid[y][x++])
		{
			if (x != 0 && y != 0 && x != ft_strlen(m->map.grid[y])
				&& y != m->map.height - 1)
			{
				tmp = ft_strtrim(m->map.grid[y], " ");
				if (tmp[0] != '1' && tmp[ft_strlen(tmp)] != '1')
					return (1);
				free(tmp);
				if (m->map.grid[y][x] == ' ')
					if (check_middle(m, y, x) == 1)
						return (1);
			}
		}
	}
	return (0);
}

static void	wall(t_master *m, char *line, int current_width)
{
	int	x;

	x = 0;
	if (current_width == 0 || current_width == m->map.height)
	{
		while (line[x])
		{
			if (line[x] != '1' && line[x] != ' ')
				exit_err(m, "Error\nMap not enclosed\n", 1);
			x++;
		}
	}
	if (wall_side(m) == 1)
		exit_err(m, "Error\nMap not enclosed\n", 1);
}

static void	valid_character(t_master *m, char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ')
		exit_err(m, "Error\nInvalid character in map\n", 1);
	if (!m->map.north_texture[0] || !m->map.south_texture[0]
		|| !m->map.west_texture[0] || !m->map.east_texture[0]
		|| !m->map.floor_colour[0] || !m->map.ceiling_colour[0])
		exit_err(m, "Error\nMissing Identifier\n", 1);
}

int	map_check(t_master *m)
{
	int	y;
	int	x;

	y = 0;
	while (m->map.grid[y])
	{
		x = 0;
		wall(m, m->map.grid[y], y);
		while (m->map.grid[y][x])
		{
			valid_character(m, m->map.grid[y][x]);
			if (m->map.grid[y][x] == 'N' || m->map.grid[y][x] == 'S'
				|| m->map.grid[y][x] == 'E' || m->map.grid[y][x] == 'W')
			{
				m->map.direction = m->map.grid[y][x];
			}
			x++;
		}
		y++;
	}
	return (0);
}
