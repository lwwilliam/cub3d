/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:03:50 by lchew             #+#    #+#             */
/*   Updated: 2023/08/04 14:44:03 by wting            ###   ########.fr       */
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
					m->map.mini_wall, j * BLOCK_SIZE, i * BLOCK_SIZE);
			++j;
		}
		++i;
	}
	return (0);
}
