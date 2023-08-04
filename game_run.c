/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/08/04 14:42:04 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hori(t_master *m, t_ray *ray)
{
	ray->atan = -1 / tan(ray->angle);
	if (ray->angle > M_PI)
	{
		ray->rayy = (int)(m->cub.posy) - 0.001;
		ray->rayx = (m->cub.posy - ray->rayy) * ray->atan + m->cub.posx;
		ray->stepy = -1;
		ray->stepx = -ray->stepy * ray->atan;
	}
	else if (ray->angle < M_PI)
	{
		ray->rayy = (int)m->cub.posy + 1.001;
		ray->rayx = (m->cub.posy - ray->rayy) * ray->atan + m->cub.posx;
		ray->stepy = 1;
		ray->stepx = -ray->stepy * ray->atan;
	}
	else
	{
		ray->rayx = m->cub.posx;
		ray->rayy = m->cub.posy;
		ray->dof = 16;
	}
}

void	run_hori(t_master *m, t_ray *ray)
{
	ray->dist_hori = 1000000;
	while (ray->dof < 16)
	{
		if (is_wall(m, (int)ray->rayx, (int)ray->rayy) == TRUE)
		{
			ray->dof = 16;
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
	}
	else if (ray->angle < (M_PI / 2) || ray->angle > (3 * M_PI / 2))
	{
		ray->rayx = (int)m->cub.posx + 1.001;
		ray->rayy = (m->cub.posx - ray->rayx) * ray->atan + m->cub.posy;
		ray->stepx = 1;
		ray->stepy = -ray->stepx * ray->atan;
	}
	else
	{
		ray->rayx = m->cub.posx;
		ray->rayy = m->cub.posy;
		ray->dof = 16;
	}
}

void	run_verti(t_master *m, t_ray *ray)
{
	ray->dist_verti = 1000000;
	while (ray->dof < 16)
	{
		if (is_wall(m, (int)ray->rayx, (int)ray->rayy) == TRUE)
		{
			ray->dof = 16;
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
}

void	raycast(t_master *m)
{
	t_ray	ray;
	int		i;

	ray.angle = m->cub.angle - ((1 * M_PI / 180) * 30);
	i = 0;
	while (i < RAYCAST)
	{
		ray.dof = 0;
		init_hori(m, &ray);
		run_hori(m, &ray);
		ray.dof = 0;
		init_verti(m, &ray);
		run_verti(m, &ray);
		if (ray.dist_hori > ray.dist_verti)
			ray.final_dist = ray.dist_verti;
		else
			ray.final_dist = ray.dist_hori;
		ray.final_dist = fisheye(m, &ray);
		printf("dist: %f\n", ray.final_dist);
		++i;
		ray.angle += ((1 * M_PI / 180) * 60) / RAYCAST;
	}
}
