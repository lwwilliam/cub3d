/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/05/17 19:01:29 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED
static void	init_game_vars(t_master *m)
{
	m->cub.n_wall = malloc(sizeof(t_texture));
	m->cub.s_wall = malloc(sizeof(t_texture));
	m->cub.e_wall = malloc(sizeof(t_texture));
	m->cub.w_wall = malloc(sizeof(t_texture));
	m->cub.posx = ((float)m->map.posx * (float)BLOCK_SIZE) + (BLOCK_SIZE / 2);
	m->cub.posy = ((float)m->map.posy * (float)BLOCK_SIZE) + (BLOCK_SIZE / 2);
	if (m->map.direction == 'N')
		m->cub.angle = 270;
	else if (m->map.direction == 'S')
		m->cub.angle = 90;
	else if (m->map.direction == 'E')
		m->cub.angle = 0;
	else if (m->map.direction == 'W')
		m->cub.angle = 180;
	m->cub.dist_proj_plane = ((float)MAP_WIDTH / 2) / tan(FOV / 2);
}

void	game(t_master *m)
{
	init_game_vars(m);
}
