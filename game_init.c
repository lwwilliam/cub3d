/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/07/01 17:04:15 by wting            ###   ########.fr       */
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
// + (BLOCK_SIZE / 2);
static void	init_game_vars(t_master *m)
{
	find_player(m);
	m->cub.posx += 0.5;
	m->cub.posx += 0.5;
	m->cub.planex = 0;
	m->cub.planey = 0.6;
	if (m->map.direction == 'N')
	{
		m->cub.angle = 90;
	}
	else if (m->map.direction == 'S')
	{
		m->cub.angle = 270;
	}
	else if (m->map.direction == 'E')
	{
		m->cub.angle = 0;
	}
	else if (m->map.direction == 'W')
	{
		m->cub.angle = 180;
	}
}

void	game(t_master *m)
{
	init_game_vars(m);
}
