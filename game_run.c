/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/08/09 18:10:46 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hori(t_master *m, t_ray *ray)
{
	ray->atan = -1 / tan(ray->angle);
	if (ray->angle > M_PI)
	{
		ray->rayy = floor(m->cub.posy) - 0.000001;
		ray->scale_hori = m->cub.posy - ray->rayy;
		ray->rayx = (m->cub.posy - ray->rayy) * ray->atan + m->cub.posx;
		ray->stepy = -1;
		ray->stepx = -ray->stepy * ray->atan;
		ray->north_south = NORTH;
	}
	else if (ray->angle < M_PI)
	{
		ray->rayy = floor(m->cub.posy) + 1.000001;
		ray->scale_hori = m->cub.posy - ray->rayy;
		ray->rayx = (m->cub.posy - ray->rayy) * ray->atan + m->cub.posx;
		ray->stepy = 1;
		ray->stepx = -ray->stepy * ray->atan;
		ray->north_south = SOUTH;
	}
	else
	{
		ray->rayx = m->cub.posx;
		ray->rayy = m->cub.posy;
		ray->dof = DOF;
	}
}

void	run_hori(t_master *m, t_ray *ray)
{
	ray->dist_hori = 1000000;
	while (ray->dof < DOF)
	{
		if (is_wall(m, (int)ray->rayx, (int)ray->rayy) == TRUE)
		{
			ray->dof = DOF;
			ray->dist_hori = get_dist(m->cub.posx, m->cub.posy, ray->rayx, \
				ray->rayy);
		}
		else
		{
			ray->rayx += ray->stepx;
			ray->rayy += ray->stepy;
			++ray->dof;
		}
	}
	if (ray->north_south == NORTH)
		ray->scale_hori = ray->rayx - floor(ray->rayx);
	else
		ray->scale_hori = 1 - (ray->rayx - floor(ray->rayx));
}

void	init_verti(t_master *m, t_ray *ray)
{
	ray->atan = -tan(ray->angle);
	if (ray->angle > (M_PI / 2) && ray->angle < (3 * M_PI / 2))
	{
		ray->rayx = floor(m->cub.posx) - 0.000001;
		ray->rayy = (m->cub.posx - ray->rayx) * ray->atan + m->cub.posy;
		ray->stepx = -1;
		ray->stepy = -ray->stepx * ray->atan;
		ray->east_west = EAST;
	}
	else if (ray->angle < (M_PI / 2) || ray->angle > (3 * M_PI / 2))
	{
		ray->rayx = floor(m->cub.posx) + 1.000001;
		ray->rayy = (m->cub.posx - ray->rayx) * ray->atan + m->cub.posy;
		ray->stepx = 1;
		ray->stepy = -ray->stepx * ray->atan;
		ray->east_west = WEST;
	}
	else
	{
		ray->rayx = m->cub.posx;
		ray->rayy = m->cub.posy;
		ray->dof = DOF;
	}
}

void	run_verti(t_master *m, t_ray *ray)
{	
	ray->dist_verti = 1000000;
	while (ray->dof < DOF)
	{
		if (is_wall(m, (int)ray->rayx, (int)ray->rayy) == TRUE)
		{
			ray->dof = DOF;
			ray->dist_verti = get_dist(m->cub.posx, m->cub.posy, ray->rayx, \
				ray->rayy);
		}
		else
		{
			ray->rayx += ray->stepx;
			ray->rayy += ray->stepy;
			++ray->dof;
		}
	}
	if (ray->east_west == WEST)
		ray->scale_verti = ray->rayy - floor(ray->rayy);
	else
		ray->scale_verti = 1 - (ray->rayy - floor(ray->rayy));
}

void	raycast(t_master *m)
{
	t_ray	ray;
	int		i;

	ray.angle = m->cub.angle - ((1 * M_PI / 180) * 30);
	i = 0;
	while (i < RAYCAST)
	{
		if (ray.angle < 0)
			ray.angle += M_PI * 2;
		if (ray.angle >= M_PI * 2)
			ray.angle -= M_PI * 2;
		ray.dof = 0;
		init_hori(m, &ray);
		run_hori(m, &ray);
		ray.dof = 0;
		init_verti(m, &ray);
		run_verti(m, &ray);
		if (ray.dist_hori > ray.dist_verti)
		{
			ray.final_dist = ray.dist_verti;
			ray.final_side = ray.east_west;
			ray.final_scale = ray.scale_verti;
		}
		else
		{
			ray.final_dist = ray.dist_hori;
			ray.final_side = ray.north_south;
			ray.final_scale = ray.scale_hori;
		}
		ray.final_dist = fisheye(m, &ray, ray.final_dist);
		ray.i = i;
		rendering(&ray, m);
		++i;
		ray.angle += ((1 * M_PI / 180) * 60) / RAYCAST;
	}
}

void north_wall2(t_ray *ray, t_master *m, int tmp, int tmp2)
{
	int		y;
	int		x;
	double	test;
	double	test2;

	y = 0;
	x = m->north->height;
	test2 = x;
	x = x / 2;
	while(y < ceil(MAP_HEIGHT / ray->final_dist) / 3)
	{
		tmp2 = ray->i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			ray->pixel = m->wall->img + (tmp * m->wall->line + tmp2 * (m->wall->bpp / 8));
			ray->pixel2 = m->north->img + (x * m->north->line + (int)(m->north->width * ray->final_scale) * (m->north->bpp / 8));
			*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, *(int *)ray->pixel2);
		}
		tmp2++;
		y++;
		test = ( m->north->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		x = test2 / 2;
		tmp = y;
		tmp += (MAP_HEIGHT / 2);
	}
}

void east_wall2(t_ray *ray, t_master *m, int tmp, int tmp2)
{
	int		y;
	int		x;
	double	test;
	double	test2;

	y = 0;
	x = m->east->height;
	test2 = x;
	x = x / 2;
	while(y < ceil(MAP_HEIGHT / ray->final_dist) / 3)
	{
		tmp2 = ray->i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			ray->pixel = m->wall->img + (tmp * m->wall->line + tmp2 * (m->wall->bpp / 8));
			ray->pixel2 = m->east->img + (x * m->east->line + (int)(m->east->width * ray->final_scale) * (m->east->bpp / 8));
			*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, *(int *)ray->pixel2);
		}
		tmp2++;
		y++;
		test = ( m->east->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		x = test2 / 2;
		tmp = y;
		tmp += (MAP_HEIGHT / 2);
	}
}

void south_wall2(t_ray *ray, t_master *m, int tmp, int tmp2)
{
	int		y;
	int		x;
	double	test;
	double	test2;

	y = 0;
	x = m->south->height;
	test2 = x;
	x = x / 2;
	while(y < ceil(MAP_HEIGHT / ray->final_dist) / 3)
	{
		tmp2 = ray->i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			ray->pixel = m->wall->img + (tmp * m->wall->line + tmp2 * (m->wall->bpp / 8));
			ray->pixel2 = m->south->img + (x * m->south->line + (int)(m->south->width * ray->final_scale) * (m->south->bpp / 8));
			*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, *(int *)ray->pixel2);
		}
		tmp2++;
		y++;
		test = ( m->south->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		x = test2 / 2;
		tmp = y;
		tmp += (MAP_HEIGHT / 2);
	}
}

void west_wall2(t_ray *ray, t_master *m, int tmp, int tmp2)
{
	int		y;
	int		x;
	double	test;
	double	test2;

	y = 0;
	x = m->west->height;
	test2 = x;
	x = x / 2;
	while(y < ceil(MAP_HEIGHT / ray->final_dist) / 3)
	{
		tmp2 = ray->i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			ray->pixel = m->wall->img + (tmp * m->wall->line + tmp2 * (m->wall->bpp / 8));
			ray->pixel2 = m->west->img + (x * m->west->line + (int)(m->west->width * ray->final_scale) * (m->west->bpp / 8));
			*(int *)ray->pixel = mlx_get_color_value(m->cub.mlx, *(int *)ray->pixel2);
		}
		tmp2++;
		y++;
		test = ( m->west->height / 2) / ((MAP_HEIGHT / ray->final_dist) / 2) * 3;
		test2 += test;
		x = test2 / 2;
		tmp = y;
		tmp += (MAP_HEIGHT / 2);
	}
}

void wall_print2(t_ray *ray, t_master *m)
{
	int y = 0;
	int x = m->north->height;
	int tmp = (MAP_HEIGHT / 2);
	int tmp2 = 0;
	double test2 = x;
	x = x / 2;

	if (ray->final_side == NORTH)
		north_wall2(ray, m, tmp, tmp2);
	else if (ray->final_side == EAST)
		east_wall2(ray, m, tmp, tmp2);
	else if (ray->final_side == SOUTH)
		south_wall2(ray, m, tmp, tmp2);
	else if (ray->final_side == WEST)
		west_wall2(ray, m, tmp, tmp2);
}

//max DOF min 0.1
void rendering(t_ray *ray, t_master *m)
{
	int y;
	int tmp;
	int tmp2;
	int colour;
	char *pixel;

	y = 0;
	colour = 0;
	tmp = MAP_HEIGHT / 2;
	wall_print(ray, m);
	wall_print2(ray, m);
}
