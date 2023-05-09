/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:03:50 by lchew             #+#    #+#             */
/*   Updated: 2023/05/09 21:35:06 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_map(t_master *m)
{
	int		i;
	int		j;

	i = 0;
	m->map.mini_wall = mlx_xpm_file_to_image(m->cub.mlx, WALL,
			&m->map.img_width, &m->map.img_height);
	while (m->map.grid[i] != NULL)
	{
		j = 0;
		while (m->map.grid[i][j] != '\0')
		{
			if (m->map.grid[i][j] == '1')
				mlx_put_image_to_window(m->cub.mlx, m->cub.win,
					m->map.mini_wall, j * 32, i * 32);
			++j;
		}
		++i;
	}
	return (0);
}