/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/08/10 15:17:04 by wting            ###   ########.fr       */
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
	int		x;
	int		y;
	char	*pixel;
	char	**split;

	pixel = m->ceiling->img;
	split = ft_split(m->map.ceiling_colour, ',');
	y = -1;
	while (++y < MAP_HEIGHT / 2)
	{
		x = -1;
		while (++x < MAP_WIDTH)
		{
			pixel = m->ceiling->img + (y * m->ceiling->line + x * \
				(m->ceiling->bpp / 8));
			*(int *)pixel = create_trgb(0, ft_atoi(split[0]), \
				ft_atoi(split[1]), ft_atoi(split[2]));
		}
	}
	free_funct(split);
}

static void	init_floor(t_master *m)
{
	int		x;
	int		y;
	char	*pixel;
	char	**split;

	pixel = m->floor->img;
	split = ft_split(m->map.floor_colour, ',');
	y = -1;
	while (++y < MAP_HEIGHT / 2)
	{
		x = -1;
		while (++x < MAP_WIDTH)
		{
			pixel = m->floor->img + (y * m->floor->line + x * \
				(m->floor->bpp / 8));
			*(int *)pixel = create_trgb(0, ft_atoi(split[0]), \
				ft_atoi(split[1]), ft_atoi(split[2]));
		}
	}
	free_funct(split);
}

void	wall_reset(t_master *m)
{
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			pixel = m->wall->img + (y * m->wall->line + x * (m->wall->bpp / 8));
			*(int *)pixel = create_trgb(225, 0, 0, 0);
			x++;
		}
		y++;
	}
}

void	wall_init2(t_master *m)
{
	m->east = malloc(sizeof(t_img));
	m->east->img_ptr = mlx_xpm_file_to_image(m->cub.mlx, m->map.east_texture, \
		&m->east->width, &m->east->height);
	m->east->img = mlx_get_data_addr(m->east->img_ptr, &m->east->bpp, \
		&m->east->line, &m->east->endian);
	m->south = malloc(sizeof(t_img));
	m->south->img_ptr = mlx_xpm_file_to_image(m->cub.mlx, \
		m->map.south_texture, &m->south->width, &m->south->height);
	m->south->img = mlx_get_data_addr(m->south->img_ptr, &m->south->bpp, \
		&m->south->line, &m->south->endian);
	m->west = malloc(sizeof(t_img));
	m->west->img_ptr = mlx_xpm_file_to_image(m->cub.mlx, m->map.west_texture, \
		&m->west->width, &m->west->height);
	m->west->img = mlx_get_data_addr(m->west->img_ptr, &m->west->bpp, \
		&m->west->line, &m->west->endian);
}

void	wall_init(t_master *m)
{
	m->wall = malloc(sizeof(t_img));
	m->wall->img_ptr = mlx_new_image(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT);
	m->wall->img = mlx_get_data_addr(m->wall->img_ptr, &m->wall->bpp, \
		&m->wall->line, &m->wall->endian);
	wall_reset(m);
	m->north = malloc(sizeof(t_img));
	m->north->img_ptr = mlx_xpm_file_to_image(m->cub.mlx, \
		m->map.north_texture, &m->north->width, &m->north->height);
	m->north->img = mlx_get_data_addr(m->north->img_ptr, &m->north->bpp, \
		&m->north->line, &m->north->endian);
	wall_init2(m);
}

void	init_images(t_master *m)
{
	m->floor = malloc(sizeof(t_img));
	m->floor->img_ptr = mlx_new_image(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT / 2);
	m->floor->img = mlx_get_data_addr(m->floor->img_ptr, &m->floor->bpp, \
		&m->floor->line, &m->floor->endian);
	m->ceiling = malloc(sizeof(t_img) * 1);
	m->ceiling->img_ptr = mlx_new_image(m->cub.mlx, MAP_WIDTH, MAP_HEIGHT / 2);
	m->ceiling->img = mlx_get_data_addr(m->ceiling->img_ptr, &m->ceiling->bpp, \
		&m->ceiling->line, &m->ceiling->endian);
}

void	game(t_master *m)
{
	init_game_vars(m);
	init_images(m);
	init_ceiling(m);
	init_floor(m);
	wall_init(m);
}
