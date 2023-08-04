/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:03:27 by wting             #+#    #+#             */
/*   Updated: 2023/08/04 23:49:03 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double degree)
{
	double	ret;

	ret = degree * M_PI / 180;
	return (ret);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	get_dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

double	fisheye(t_master *m, t_ray *ray, double i)
{
	double	ret;

	ret = m->cub.angle - ray->angle;
	if (ret < 0)
		ret += 2 * M_PI;
	if (ret > 2 * M_PI)
		ret -= 2 * M_PI;
	return (i * cos(ret));
}

int	is_wall(t_master *m, int x, int y)
{
	if (x < 0 || y < 0 || y >= m->map.height || x >= ft_strlen(m->map.grid[y]))
		return (FALSE);
	if (m->map.grid[y][x] == '1')
		return (TRUE);
	else
		return (FALSE);
}
