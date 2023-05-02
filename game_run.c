/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/05/02 22:25:09 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED

void	move_char(t_master *master, int direction)
{
	t_cub *cub;
	
	cub = master->m_cub;
	if (direction == FORWARD)
	{
		cub->posx += cos(deg_to_rad(cub->angle)) * SPEED;
		cub->posy += sin(deg_to_rad(cub->angle)) * SPEED;
	}
	else if (direction == BACKWARD)
	{
		cub->posx += cos(deg_to_rad(cub->angle)) * (SPEED * -1);
		cub->posy += sin(deg_to_rad(cub->angle)) * (SPEED * -1);
	}
	else if (direction == LEFT)
	{
		cub->posx += cos(deg_to_rad(cub->angle)) * (SPEED * -1);
		cub->posy += sin(deg_to_rad(cub->angle)) * SPEED;
	}
	else if (direction == RIGHT)
	{
		cub->posx += cos(deg_to_rad(cub->angle)) * SPEED;
		cub->posy += sin(deg_to_rad(cub->angle)) * (SPEED * -1);
	}	
}

void	raycast(t_master *master)
{
	while ()
}