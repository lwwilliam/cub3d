/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/05/19 22:08:57 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED
static void	init_game_vars(t_master *m)
{
	m->cub.posx = ((float)m->map.posx * (float)BLOCK_SIZE) + (BLOCK_SIZE / 2);
	m->cub.posy = ((float)m->map.posy * (float)BLOCK_SIZE) + (BLOCK_SIZE / 2);
	if (m->map.direction == 'N')
		m->cub.angle = 0;
	else if (m->map.direction == 'S')
		m->cub.angle = 180;
	else if (m->map.direction == 'E')
		m->cub.angle = 90;
	else if (m->map.direction == 'W')
		m->cub.angle = 270;
}

static void	ceiling_init(t_master *m)
{
	int		x;
	int		y;
	char	*pixel;
	char 	**split;

	m->img.ceiling_img = mlx_new_image(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT / 2);
	m->img.ceiling = mlx_get_data_addr(m->img.ceiling_img, &m->img.c_bpp, &m->img.c_line, &m->img.c_endian);
	pixel = m->img.ceiling;
	split = ft_split(m->map.ceiling_colour, ',');
	y = 0;
	while (y < MAP_HEIGHT / 2)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			pixel = m->img.ceiling + (y * m->img.c_line + x * (m->img.c_bpp / 8));
			*(int *)pixel = create_trgb(0, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
			x++;
		}
		y++;
	}
	free_funct(split);
}

static void	floor_init(t_master *m)
{
	int		x;
	int		y;
	char	*pixel;
	char 	**split;

	m->img.floor_img = mlx_new_image(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT / 2);
	m->img.floor = mlx_get_data_addr(m->img.floor_img, &m->img.f_bpp, &m->img.f_line, &m->img.f_endian);
	pixel = m->img.floor;
	split = ft_split(m->map.floor_colour, ',');
	y = 0;
	while (y < MAP_HEIGHT / 2)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			pixel = m->img.floor + (y * m->img.f_line + x * (m->img.f_bpp / 8));
			*(int *)pixel = create_trgb(0, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
			x++;
		}
		y++;
	}
	free_funct(split);
}

static void	cockpit_init(t_master *m)
{
	char	*halo_path;
	int		img_width;
	int		img_height;

	halo_path = "./xpm/f1.xpm";
	m->img.up_path = "./xpm/up.xpm";
	m->img.left_path = "./xpm/left.xpm";
	m->img.right_path = "./xpm/right.xpm";
	m->img.halo = mlx_xpm_file_to_image(m->cub.mlx, halo_path, &img_width, &img_height);
	m->img.wheel = mlx_xpm_file_to_image(m->cub.mlx, m->img.up_path, &img_width, &img_height);
}

void	game(t_master *m)
{
	init_game_vars(m);
	ceiling_init(m);
	floor_init(m);
	cockpit_init(m);
}
