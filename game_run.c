/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:51:16 by wting             #+#    #+#             */
/*   Updated: 2023/07/01 18:26:15 by wting            ###   ########.fr       */
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

static void	get_hori(t_master *m, double angle, t_vect *vect)
{
}

static void	get_vert(t_master *m, double angle, t_vect *vect)
{
}

double	get_dist(t_master *m)
{
	int	mapx;
	int	mapy;
	
	mapx = (int)m->cub.posx;
	mapy = (int)m->cub.posy;
	
}

void	raycast(t_master *m)
{
	// double	i;
	int		i;
	double	camx;
	double	dirx;
	double	diry;
	i = 0;
	dirx = cos(deg_to_rad(m->cub.angle));
	diry = sin(deg_to_rad(m->cub.angle));
	while (i++ < MAP_WIDTH)
	{
		camx = 2 * i / (double)MAP_WIDTH - 1;
		m->cub.rayx = dirx + m->cub.planex * camx;
		m->cub.rayy = diry + m->cub.planey * camx;
		get_dist(m);
	}
}