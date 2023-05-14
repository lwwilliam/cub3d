/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:03:50 by lchew             #+#    #+#             */
/*   Updated: 2023/05/14 17:22:01 by lchew            ###   ########.fr       */
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
	load_texture(m);
	return (0);
}

void	load_texture(t_master *m)
{
	m->cub.n_wall->img = mlx_xpm_file_to_image(m->cub.mlx, m->map.north_texture,
			&m->cub.n_wall->width, &m->cub.n_wall->height);
	m->cub.s_wall->img = mlx_xpm_file_to_image(m->cub.mlx, m->map.south_texture,
			&m->cub.s_wall->width, &m->cub.s_wall->height);
	m->cub.e_wall->img = mlx_xpm_file_to_image(m->cub.mlx, m->map.east_texture,
			&m->cub.e_wall->width, &m->cub.e_wall->height);
	m->cub.w_wall->img = mlx_xpm_file_to_image(m->cub.mlx, m->map.west_texture,
			&m->cub.w_wall->width, &m->cub.w_wall->height);
	if (!m->cub.n_wall->img || !m->cub.s_wall->img
		|| !m->cub.e_wall->img || !m->cub.w_wall->img)
		exit_error("Error\nTexture not found\n");
	m->cub.n_wall->addr = mlx_get_data_addr(m->cub.n_wall->img,
			&m->cub.n_wall->bpp, &m->cub.n_wall->line_length,
			&m->cub.n_wall->endian);
	m->cub.s_wall->addr = mlx_get_data_addr(m->cub.s_wall->img,
			&m->cub.s_wall->bpp, &m->cub.s_wall->line_length,
			&m->cub.s_wall->endian);
	m->cub.e_wall->addr = mlx_get_data_addr(m->cub.e_wall->img,
			&m->cub.e_wall->bpp, &m->cub.e_wall->line_length,
			&m->cub.e_wall->endian);
	m->cub.w_wall->addr = mlx_get_data_addr(m->cub.w_wall->img,
			&m->cub.w_wall->bpp, &m->cub.w_wall->line_length,
			&m->cub.w_wall->endian);
}
