/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/08/04 19:29:24 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED
static void	find_player(t_master *m)
{
	int	i;
	int	j;

	j = -1;
	while (m->map.grid[++j])
	{
		i = -1;
		while (m->map.grid[j][++i])
		{
			if (m->map.grid[j][i] == 'N' || m->map.grid[j][i] == 'S' || \
				m->map.grid[j][i] == 'E' || m->map.grid[j][i] == 'W')
			{
				m->cub.posx = (double)i;
				m->cub.posy = (double)j;
			}
		}
	}
}

static void	init_game_vars(t_master *m)
{
	find_player(m);
	m->cub.posx += 0.5;
	m->cub.posy += 0.5;
	if (m->map.direction == 'N')
		m->cub.angle = M_PI + (M_PI / 2);
	else if (m->map.direction == 'S')
		m->cub.angle = M_PI / 2;
	else if (m->map.direction == 'E')
		m->cub.angle = 0;
	else if (m->map.direction == 'W')
		m->cub.angle = M_PI;
	m->cub.pdx = cos(m->cub.angle) * SPEED;
	m->cub.pdy = sin(m->cub.angle) * SPEED;
}

static void	init_ceiling(t_master *m)
{
	int x;
	int y;
	char *pixel;
	char **split;

	m->ceiling = malloc(sizeof(t_img) * 1);
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

void wall_reset(t_master *m)
{
	int		x;
	int		y;
	char 	*pixel;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			pixel = m->test->img + (y * m->test->line + x * (m->test->bpp / 8));
			*(int *)pixel = create_trgb(225, 0, 0, 0);
			x++;
		}
		y++;
	}
}

void wall_init(t_master *m)
{
	m->test = malloc(sizeof(t_img));
	m->test->img_ptr = mlx_new_image(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT);
	m->test->img = mlx_get_data_addr(m->test->img_ptr, &m->test->bpp, &m->test->line, &m->test->endian);
	wall_reset(m);

	// char	*pixel2;
	// void *t_ptr;
	// char *text_addr;
	// int w, h = 0;
	// y = 0;
	// int bpp, line, endian = 0;
	// int tmp = 0;
	// t_ptr = mlx_xpm_file_to_image(m->cub.mlx, "./xpm/test-_1_.xpm", &w, &h);
	// text_addr = mlx_get_data_addr(t_ptr, &bpp, &line, &endian);
	// while (y < h)
	// {
	// 	x = 0;
	// 	while (x < w)
	// 	{
	// 		pixel = m->test->img + (tmp * m->test->line + x * (m->test->bpp / 8));
	// 		pixel2 = text_addr + (y * line + x * (bpp / 8));
	// 		*(int *)pixel = mlx_get_color_value(m->cub.mlx, *(int *)pixel2);
	// 		x++;
	// 	}
	// 	y++;
	// 	tmp = y;
	// 	tmp += 100;
	// }
}

void	game(t_master *m)
{
	init_game_vars(m);
	init_ceiling(m);
	init_floor(m);
	wall_init(m);
}
