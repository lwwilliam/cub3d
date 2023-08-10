/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:13:29 by lwilliam          #+#    #+#             */
/*   Updated: 2023/08/10 15:34:07 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	north_wall(t_ray *ray, t_master *m, int tmp, int tmp2)
{
	int		y;
	int		x;
	double	test;
	double	test2;

	y = ceil(MAP_HEIGHT / 2) - (MAP_HEIGHT / ray->final_dist) / 3;
	x = 0;
	test = 0;
	test2 = 0;
	while (y < ceil(MAP_HEIGHT / 2))
	{
		tmp2 = ray->i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			ray->pixel = m->wall->img + (y * m->wall->line + tmp2 * (m->wall->bpp / 8));
			ray->pixel2 = m->north->img + (x * m->north->line + ((int)(m->north->width * ray->final_scale) * (m->north->bpp / 8)));
			*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, *(int *)ray->pixel2);
		}
		tmp2++;
		y++;
		test = ( m->north->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		x = test2 / 2;
	}
}

void	east_wall(t_ray *ray, t_master *m, int tmp, int tmp2)
{
	int		y;
	int		x;
	double	test;
	double	test2;

	y = ceil(MAP_HEIGHT / 2) - (MAP_HEIGHT / ray->final_dist) / 3;
	x = 0;
	test = 0;
	test2 = 0;
	while (y < ceil(MAP_HEIGHT / 2))
	{
		tmp2 = ray->i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			ray->pixel = m->wall->img + (y * m->wall->line + tmp2 * (m->wall->bpp / 8));
			ray->pixel2 = m->east->img + (x * m->east->line + ((int)(m->east->width * ray->final_scale) * (m->east->bpp / 8)));
			*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, *(int *)ray->pixel2);
		}
		tmp2++;
		y++;
		test = ( m->east->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		x = test2 / 2;
	}
}

void	south_wall(t_ray *ray, t_master *m, int tmp, int tmp2)
{
	int		y;
	int		x;
	double	test;
	double	test2;

	y = ceil(MAP_HEIGHT / 2) - (MAP_HEIGHT / ray->final_dist) / 3;
	x = 0;
	test = 0;
	test2 = 0;
	while (y < ceil(MAP_HEIGHT / 2))
	{
		tmp2 = ray->i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			ray->pixel = m->wall->img + (y * m->wall->line + tmp2 * (m->wall->bpp / 8));
			ray->pixel2 = m->south->img + (x * m->south->line + ((int)(m->south->width * ray->final_scale) * (m->south->bpp / 8)));
			*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, *(int *)ray->pixel2);
		}
		tmp2++;
		y++;
		test = ( m->south->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		x = test2 / 2;
	}
}

void west_wall(t_ray *ray, t_master *m, int tmp, int tmp2)
{
	int		y;
	int		x;
	double	test;
	double	test2;

	y = ceil(MAP_HEIGHT / 2) - (MAP_HEIGHT / ray->final_dist) / 3;
	x = 0;
	test = 0;
	test2 = 0;
	while(y < ceil(MAP_HEIGHT / 2))
	{
		tmp2 = ray->i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			ray->pixel = m->wall->img + (y * m->wall->line + tmp2 * (m->wall->bpp / 8));
			ray->pixel2 = m->west->img + (x * m->west->line + ((int)(m->west->width * ray->final_scale) * (m->west->bpp / 8)));
			*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, *(int *)ray->pixel2);
		}
		tmp2++;
		y++;
		test = (m->west->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		x = test2 / 2;
	}
}

void wall_print(t_ray *ray, t_master *m)
{
	int tmp;
	int tmp2;

	tmp = 0;
	tmp2 = 0;
	if (ray->final_side == NORTH)
		north_wall(ray, m, tmp, tmp2);
	else if (ray->final_side == EAST)
		east_wall(ray, m, tmp, tmp2);
	else if (ray->final_side == SOUTH)
		south_wall(ray, m, tmp, tmp2);
	else if (ray->final_side == WEST)
		west_wall(ray, m, tmp, tmp2);
}