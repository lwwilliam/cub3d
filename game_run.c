/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/08/10 17:21:12 by lwilliam         ###   ########.fr       */
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

void	assign_final(t_master *m, t_ray *ray)
{
	if (ray->dist_hori > ray->dist_verti)
	{
		ray->final_dist = ray->dist_verti;
		ray->final_side = ray->east_west;
		ray->final_scale = ray->scale_verti;
	}
	else
	{
		ray->final_dist = ray->dist_hori;
		ray->final_side = ray->north_south;
		ray->final_scale = ray->scale_hori;
	}
	ray->final_dist = fisheye(m, ray, ray->final_dist);
}
