/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/08/04 23:32:30 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hori(t_master *m, t_ray *ray)
{
	ray->atan = -1 / tan(ray->angle);
	if (ray->angle > M_PI)
	{
		ray->rayy = (int)(m->cub.posy) - 0.001;
		ray->scale_hori = m->cub.posy - ray->rayy;
		ray->rayx = (m->cub.posy - ray->rayy) * ray->atan + m->cub.posx;
		ray->stepy = -1;
		ray->stepx = -ray->stepy * ray->atan;
		ray->north_south = NORTH;
	}
	else if (ray->angle < M_PI)
	{
		ray->rayy = (int)m->cub.posy + 1.001;
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
		ray->rayx = (int)(m->cub.posx) - 0.001;
		ray->rayy = (m->cub.posx - ray->rayx) * ray->atan + m->cub.posy;
		ray->stepx = -1;
		ray->stepy = -ray->stepx * ray->atan;
		ray->east_west = EAST;
	}
	else if (ray->angle < (M_PI / 2) || ray->angle > (3 * M_PI / 2))
	{
		ray->rayx = (int)m->cub.posx + 1.001;
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
		ray.final_dist = fisheye(m, &ray);
		rendering(&ray, m, i);
		++i;
		ray.angle += ((1 * M_PI / 180) * 60) / RAYCAST;
	}
}

//max DOF min 0.1
void rendering(t_ray *ray, t_master *m, int i)
{
	int y;
	int tmp;
	int tmp2;
	char *pixel;

	y = 0;
	tmp = MAP_HEIGHT / 2;
	if (ray->final_dist < 0.2 )
		ray->final_dist = 0.2;
	while(y < ceil(MAP_HEIGHT / ray->final_dist))
	{
		tmp2 = i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			pixel = m->test->img + (tmp * m->test->line + tmp2 * (m->test->bpp / 8));
			*(int *)pixel = create_trgb(0, 0, 255, 0);
		}
		tmp2++;
		y++;
		tmp = MAP_HEIGHT / 2 - y;
	}
	tmp = 0;
	y = 0;
	while(y < ceil(MAP_HEIGHT / ray->final_dist))
	{
		tmp2 = i;
		if (y < MAP_HEIGHT && y >= 0 && tmp < MAP_HEIGHT && tmp >= 0)
		{
			pixel = m->test->img + (tmp * m->test->line + tmp2 * (m->test->bpp / 8));
			*(int *)pixel = create_trgb(0, 0, 255, 0);
		}
		tmp2++;
		y++;
		tmp = y;
		tmp += (MAP_HEIGHT / 2);
	}
}
