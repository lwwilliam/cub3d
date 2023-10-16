/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/08/11 14:55:34 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED
static void	find_player(t_master *m)
{
	int	i;
	int	j;

	j = -1;
	while (m->map.grid[++j])
	{
		i = -1;
		while (m->map.grid[j][++i])
		{
			if (m->map.grid[j][i] == 'N' || m->map.grid[j][i] == 'S' || \
				m->map.grid[j][i] == 'E' || m->map.grid[j][i] == 'W')
			{
				m->cub.posx = (double)i;
				m->cub.posy = (double)j;
			}
		}
	}
}

static void	init_game_vars(t_master *m)
{
	find_player(m);
	m->cub.posx += 0.5;
	m->cub.posy += 0.5;
	if (m->map.direction == 'N')
		m->cub.angle = M_PI + (M_PI / 2);
	else if (m->map.direction == 'S')
		m->cub.angle = M_PI / 2;
	else if (m->map.direction == 'E')
		m->cub.angle = 0;
	else if (m->map.direction == 'W')
		m->cub.angle = M_PI;
	m->cub.pdx = cos(m->cub.angle) * SPEED;
	m->cub.pdy = sin(m->cub.angle) * SPEED;
}

static void	init_ceiling(t_master *m)
{
	int		x;
	int		y;
	char	*pixel;
	char	**split;

	pixel = m->ceiling->img;
	split = ft_split(m->map.ceiling_colour, ',');
	y = -1;
	while (++y < MAP_HEIGHT / 2)
	{
		x = -1;
		while (++x < MAP_WIDTH)
		{
			pixel = m->ceiling->img + (y * m->ceiling->line + x * \
				(m->ceiling->bpp / 8));
			*(int *)pixel = create_trgb(0, ft_atoi(split[0]), \
				ft_atoi(split[1]), ft_atoi(split[2]));
		}
	}
	free_funct(split);
}

static void	init_floor(t_master *m)
{
	int		x;
	int		y;
	char	*pixel;
	char	**split;

	pixel = m->floor->img;
	split = ft_split(m->map.floor_colour, ',');
	y = -1;
	while (++y < MAP_HEIGHT / 2)
	{
		x = -1;
		while (++x < MAP_WIDTH)
		{
			pixel = m->floor->img + (y * m->floor->line + x * \
				(m->floor->bpp / 8));
			*(int *)pixel = create_trgb(0, ft_atoi(split[0]), \
				ft_atoi(split[1]), ft_atoi(split[2]));
		}
	}
	free_funct(split);
}

void	game(t_master *m)
{
	init_game_vars(m);
	init_images(m);
	init_ceiling(m);
	init_floor(m);
	wall_init(m);
	init_cockpit(m);
}
