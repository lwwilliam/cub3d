/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/05/24 18:49:33 by yalee            ###   ########.fr       */
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
		m->cub.angle = 270;
	else if (m->map.direction == 'S')
		m->cub.angle = 90;
	else if (m->map.direction == 'E')
		m->cub.angle = 0;
	else if (m->map.direction == 'W')
		m->cub.angle = 180;
}

static void	init_ceiling(t_master *m)
{
	int x;
	int y;
	char *pixel;
	char **split;

	m->ceiling = malloc(sizeof(t_img));
	m->ceiling->img_ptr = mlx_new_image(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT / 2);
	m->ceiling->img = mlx_get_data_addr(m->ceiling->img_ptr, &m->ceiling->bpp, &m->ceiling->line, &m->ceiling->endian);
	pixel = m->ceiling->img;
	split = ft_split(m->map.ceiling_colour, ',');
	y = 0;
	while (y < MAP_HEIGHT / 2)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			pixel = m->ceiling->img + (y * m->ceiling->line + x * (m->ceiling->bpp / 8));
			*(int *)pixel = create_trgb(0, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
			x++;
		}
		y++;
	}
	free_funct(split);
}

static void init_floor(t_master *m)
{
	int x;
	int y;
	char *pixel;
	char **split;

	m->floor = malloc(sizeof(t_img));
	m->floor->img_ptr = mlx_new_image(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT / 2);
	m->floor->img = mlx_get_data_addr(m->floor->img_ptr, &m->floor->bpp, &m->floor->line, &m->floor->endian);
	pixel = m->floor->img;
	split = ft_split(m->map.floor_colour, ',');
	y = 0;
	while (y < MAP_HEIGHT / 2)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			pixel = m->floor->img + (y * m->floor->line + x * (m->floor->bpp / 8));
			*(int *)pixel = create_trgb(0, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
			x++;
		}
		y++;
	}
	free_funct(split);
}

static void	init_cockpit(t_master *m)
{
	char *halo_path;
	int img_width;
	int img_height;

	halo_path = "./xpm/f1.xpm";
	m->cub.up_path = "./xpm/up.xpm";
	m->cub.left_path = "./xpm/left.xpm";
	m->cub.right_path = "./xpm/right.xpm";
	m->cub.halo = mlx_xpm_file_to_image(m->cub.mlx, halo_path, &img_width, &img_height);
	m->cub.wheel = mlx_xpm_file_to_image(m->cub.mlx, m->cub.up_path, &img_width, &img_height);
}

void	game(t_master *m)
{
	init_game_vars(m);
	init_ceiling(m);
	init_floor(m);
	init_cockpit(m);
	// init_wall(m);
}
