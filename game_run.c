/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/05/29 18:24:07 by wting            ###   ########.fr       */
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

static void	get_hori(t_master *m, float angle, t_vect *vect)
{
	int	x_inc;
	int	y_inc;
	
	if (angle <= 180)
	{
		vect->A.y_float = (int)(m->cub.posy / BLOCK_SIZE) * BLOCK_SIZE - 1;
		y_inc = -1 * BLOCK_SIZE;
	}
	else
	{
		vect->A.y_float = (int)(m->cub.posy / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
		y_inc = BLOCK_SIZE;
	}
	vect->A.x_float = m->cub.posx + ((m->cub.posy - vect->A.y_float) \
		/ tan(deg_to_rad(m->cub.angle)));
	x_inc = BLOCK_SIZE / tan(deg_to_rad(angle));
	while (is_wall(m, (int)(vect->A.x_float), (int)(vect->A.y_float)) == FALSE)
	{
		vect->A.x_float += x_inc;
		vect->A.y_float += y_inc;
	}
}

static void	get_vert(t_master *m, float angle, t_vect *vect)
{
	int	x_inc;
	int	y_inc;

	if (angle < 90 || angle >= 270)
	{
		vect->B.x_float = (int)(m->cub.posx / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
		x_inc = BLOCK_SIZE;
	}
	else
	{
		vect->B.x_float = (int)(m->cub.posx / BLOCK_SIZE) * BLOCK_SIZE - 1;
		x_inc = BLOCK_SIZE * -1;
	}
	vect->B.y_float = m->cub.posy + (m->cub.posx - vect->B.x_float) \
		* tan(deg_to_rad(angle));
	y_inc = BLOCK_SIZE * tan(deg_to_rad(angle));
	while (is_wall(m, (int)(vect->B.x_float), (int)(vect->B.y_float)) == FALSE)
	{
		vect->B.x_float += x_inc;
		vect->B.y_float += y_inc;
	}
}

float	get_dist(t_master *m, float angle)
{
	float	tmp1;
	float	tmp2;
	t_vect	vect;

	get_hori(m, angle, &vect);
	get_vert(m, angle, &vect);
	tmp1 = fabs((m->cub.posx - vect.A.x_float) / BLOCK_SIZE / cos(deg_to_rad(angle)));
	tmp2 = fabs((m->cub.posx - vect.B.x_float) / BLOCK_SIZE / cos(deg_to_rad(angle)));
	if (tmp1 < tmp2 || tmp2 < 0)
		return (tmp1);
	return (tmp2);
}

void	raycast(t_master *m)
{
	float	i;
	int		x;

	x = 0;
	i = m->cub.angle + (FOV / 2);
	while (x++ <= RAYCAST)
	{
		printf("dist: %f | angle:%f\n", get_dist(m, i), i);
		i -= FOV / RAYCAST;
	}
}