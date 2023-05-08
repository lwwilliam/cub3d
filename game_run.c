/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/05/05 15:11:34 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// float	get_dist(t_cub *cub, t_map *map, float angle)
// {
	
// }

void	raycast(t_master *m)
{
	int		i;

	i = m->cub.angle - (FOV / 2);
	i = m->cub.angle + (FOV / 2);
	i = 0;
	while (i < RAYCAST)
	{
		// get_dist(cub, map, (cub->angle - (FOV / 2)) + (i * FOV / RAYCAST));
		++i;
	}
}