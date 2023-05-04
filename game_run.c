/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/05/04 17:39:47 by wting            ###   ########.fr       */
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

// float	get_dist(t_cub *cub, t_map *map, float angle)
// {
	
// }

void	raycast(t_master *master)
{
	int		i;
	t_cub	*cub;
	t_map	*map;

	map = master->m_map;
	cub = master->m_cub;
	i = 0;
	cub->angle - (FOV / 2);
	cub->angle + (FOV / 2);

	while (i < RAYCAST);
	{
		// get_dist(cub, map, (cub->angle - (FOV / 2)) + (i * FOV / RAYCAST));
		++i;
	}
}