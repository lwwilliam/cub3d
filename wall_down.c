/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:47:19 by lwilliam          #+#    #+#             */
/*   Updated: 2023/08/10 16:56:06 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_render_down2(t_ray *ray, t_master *m, t_img *dir)
{
	if (ray->y < MAP_HEIGHT && ray->y >= 0 && ray->tmp < MAP_HEIGHT \
		&& ray->tmp >= 0)
	{
		ray->pixel = m->wall->img + (ray->tmp * m->wall->line + ray->tmp2 * \
			(m->wall->bpp / 8));
		ray->pixel2 = dir->img + (ray->x * dir->line + (int)(dir->width * \
			ray->final_scale) * (dir->bpp / 8));
		*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, \
			*(int *)ray->pixel2);
	}
}

void	wall_render_down(t_ray *ray, t_master *m, t_img *dir)
{
	double	test;
	double	test2;

	ray->y = 0;
	ray->x = dir->height;
	test2 = ray->x;
	ray->x = ray->x / 2;
	while (ray->y < ceil(MAP_HEIGHT / ray->final_dist) / 3)
	{
		ray->tmp2 = ray->i;
		wall_render_down2(ray, m, dir);
		ray->tmp2++;
		ray->y++;
		test = (dir->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		ray->x = test2 / 2;
		ray->tmp = ray->y;
		ray->tmp += (MAP_HEIGHT / 2);
	}
}

void	wall_print2(t_ray *ray, t_master *m)
{
	int	y;

	y = 0;
	ray->tmp = (MAP_HEIGHT / 2);
	ray->tmp2 = 0;
	if (ray->final_side == NORTH)
		wall_render_down(ray, m, m->north);
	else if (ray->final_side == EAST)
		wall_render_down(ray, m, m->east);
	else if (ray->final_side == SOUTH)
		wall_render_down(ray, m, m->south);
	else if (ray->final_side == WEST)
		wall_render_down(ray, m, m->west);
}
