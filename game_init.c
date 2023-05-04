/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/05/04 18:10:04 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED
static void	init_game_vars(t_master *m)
{
	m->cub.posy = (float)m->map.posy * (float)BLOCK_SIZE;
	m->cub.posx = (float)m->map.posx * (float)BLOCK_SIZE;
	if (m->map.direction == 'N')
		m->cub.angle = 0;
	else if (m->map.direction == 'S')
		m->cub.angle = 180;
	else if (m->map.direction == 'E')
		m->cub.angle = 90;
	else if (m->map.direction == 'W')
		m->cub.angle = 270;
}

void	game(t_master *m)
{
	init_game_vars(m);
}
