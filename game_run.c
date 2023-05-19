/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/05/09 17:49:14 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// float	get_dist(t_master *m)
// {
	
// }
void	raycast(t_master *m)
{
	float	i;
	float	max;
	// float	dist;

	i = m->cub.angle - (FOV / 2);
	max = m->cub.angle + (FOV / 2);
	while (i <= max)
	{
		// m->cub.dist = get_dist(m);
		// draw_ray(m);
		i += FOV / RAYCAST;
	}
}