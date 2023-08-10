/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:13:29 by lwilliam          #+#    #+#             */
/*   Updated: 2023/08/10 17:14:27 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_render_up2(t_ray *ray, t_master *m, t_img *dir)
{
	if (ray->y < MAP_HEIGHT && ray->y >= 0 && ray->tmp < MAP_HEIGHT \
		&& ray->tmp >= 0)
	{
		ray->pixel = m->wall->img + (ray->y * m->wall->line + ray->tmp2 * \
			(m->wall->bpp / 8));
		ray->pixel2 = dir->img + (ray->x * dir->line + \
			((int)(dir->width * ray->final_scale) * (dir->bpp / 8)));
		*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, \
			*(int *)ray->pixel2);
	}
}

void	wall_render_up(t_ray *ray, t_master *m,	t_img *dir)
{
	double	test;
	double	test2;

	ray->y = ceil(MAP_HEIGHT / 2) - (MAP_HEIGHT / ray->final_dist) / 3;
	ray->x = 0;
	test = 0;
	test2 = 0;
	while (ray->y < ceil(MAP_HEIGHT / 2))
	{
		ray->tmp2 = ray->i;
		wall_render_up2(ray, m, dir);
		ray->tmp2++;
		ray->y++;
		test = (dir->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) \
			* 3;
		test2 += test;
		ray->x = test2 / 2;
	}
}

void	wall_print(t_ray *ray, t_master *m)
{
	ray->tmp = 0;
	ray->tmp2 = 0;
	if (ray->final_side == NORTH)
		wall_render_up(ray, m, m->north);
	else if (ray->final_side == EAST)
		wall_render_up(ray, m, m->east);
	else if (ray->final_side == SOUTH)
		wall_render_up(ray, m, m->south);
	else if (ray->final_side == WEST)
		wall_render_up(ray, m, m->west);
}
