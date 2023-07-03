/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/07/03 22:41:50 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(t_master *m, int x, int y)
{
	x /= BLOCK_SIZE;
	y /= BLOCK_SIZE;
	if (x < 0 || y < 0 || y >= m->map.height || x >= ft_strlen(m->map.grid[y]))
		return (TRUE);
	if (m->map.grid[y][x] == '1')
		return (TRUE);
	else
		return (FALSE);
}

void	check_hit(t_master *m, t_ray ray, double dx, double dy)
{
	int	hit;
	int	side;
	hit = FALSE;
	
	while (hit == FALSE)
	{
		if (ray.distx < ray.disty)
		{
			ray.distx += dx; 
			side = NORTH_SOUTH;
		}
		else
		{
			ray.distx += dy;
			side = EAST_WEST;
		}
		hit = is_wall(m, (int)ray.distx, (int)ray.disty);
	}
	if (side == NORTH_SOUTH)
	{
		ray.distx -= dx;
		// print_wall();
		printf("dist:%f\n", ray.distx);
	}
	else
	{
		ray.disty -= dy;
		// print_wall();
		printf("dist:%f\n", ray.disty);
	}
}

void	get_dist(t_master *m, double dx, double dy)
{
	t_ray ray;

	if (m->cub.rayx < 0)
	{
		ray.stepx = -1;
		ray.distx = (m->cub.posx - (int)m->cub.posx) * dx;
	}
	else
	{
		ray.stepx = 1;
		ray.distx = (m->cub.posx + 1 - (int)m->cub.posx) * dx;
	}
	if (m->cub.rayy < 0)
	{
		ray.stepy = -1;
		ray.disty = (m->cub.posy - (int)m->cub.posy) * dy;
	}
	else
	{
		ray.stepy = 1;
		ray.disty = (m->cub.posy + 1 - (int)m->cub.posy) * dy;
	}
	check_hit(m, ray, dx, dy);
}

void	raycast(t_master *m)
{
	double	i;
	double	camx;
	double	dirx;
	double	diry;
	double	dx;
	double	dy;

	i = 0;
	dirx = cos(deg_to_rad(m->cub.angle));
	diry = sin(deg_to_rad(m->cub.angle));
	if (dirx == 0)
		dx = INT_MAX;
	else
		dx = fabs(1 / dirx);
	if (diry == 0)
		dy = INT_MAX;
	else
		dy = fabs(1 / diry);
	printf("\n\n\n-------------------------\n");
	while (i++ < MAP_WIDTH)
	{
		camx = 2 * i / (double)MAP_WIDTH - 1;
		m->cub.rayx = dirx + m->cub.planex * camx;
		m->cub.rayy = diry + m->cub.planey * camx;
		get_dist(m, dx, dy);
	}
}