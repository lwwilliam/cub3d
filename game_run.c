/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/05/17 19:21:02 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical_slice(t_cub *cub, t_texture *wall, float dist)
{
	int		i;
	int		j;
	int		color;
	float	perp_dist;

	cub->slice_height = wall->height * cub->dist_proj_plane / dist;
	i = 0;
	while (i < m->cub.r_height)
	{
		j = 0;
		while (j < m->cub.r_width)
		{
			perp_dist = m->cub.dist * cos(m->cub.angle - m->cub.ray_angle);
			color = get_texture_color(m, perp_dist, j);
			my_mlx_pixel_put(m, j, i, color);
			j++;
		}
		i++;
	}
}
// float	get_dist(t_master *m)
// {
	
// }
void	raycast(t_master *m)
{
	float	i;
	float	max;
	float	dist;

	i = m->cub.angle - (FOV / 2);
	max = m->cub.angle + (FOV / 2);
	while (i <= max)
	{
		dist = get_dist(m);
		draw_vertical_slice(&m->cub, m->cub.n_wall, dist);
		i += FOV / MAP_WIDTH;
	}
}