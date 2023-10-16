/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:20:59 by lwilliam          #+#    #+#             */
/*   Updated: 2023/08/10 17:21:18 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_master *m)
{
	t_ray	ray;
	int		i;

	ray.angle = m->cub.angle - ((1 * M_PI / 180) * (FOV / 2));
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
		assign_final(m, &ray);
		ray.i = i;
		++i;
		rendering(&ray, m);
		ray.angle += ((1 * M_PI / 180) * 60) / RAYCAST;
	}
}

//max DOF min 0.1
void	rendering(t_ray *ray, t_master *m)
{
	int		y;
	int		tmp;
	int		tmp2;
	int		colour;
	char	*pixel;

	y = 0;
	colour = 0;
	tmp = MAP_HEIGHT / 2;
	wall_print(ray, m);
	wall_print2(ray, m);
}
