/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:58 by lchew             #+#    #+#             */
/*   Updated: 2023/08/10 17:16:15 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// posx = cos(angle) * SPEED
// pos𝑦 = sin(angle) * SPEED

static void	move_char2(t_master *m, int direction, int *count)
{
	double	x_inc;
	double	y_inc;

	x_inc = cos(m->cub.angle - (M_PI / 2)) * SPEED;
	y_inc = sin(m->cub.angle - (M_PI / 2)) * SPEED;
	if (direction == LEFT && \
		is_wall(m, m->cub.posx + x_inc, m->cub.posy + y_inc) == FALSE)
	{
		m->cub.posx += x_inc;
		m->cub.posy += y_inc;
		++(*count);
	}
	if (direction == RIGHT && \
	is_wall(m, m->cub.posx - x_inc, m->cub.posy - y_inc) == FALSE)
	{
		m->cub.posx -= x_inc;
		m->cub.posy -= y_inc;
		++(*count);
	}
}

static void	move_char(t_master *m, int direction, int *count)
{
	if (direction == FORWARD && is_wall(m, m->cub.posx + m->cub.pdx, \
		m->cub.posy + m->cub.pdy) == FALSE)
	{
			m->cub.posx += m->cub.pdx;
			m->cub.posy += m->cub.pdy;
			++(*count);
	}
	if (direction == BACKWARD && is_wall(m, m->cub.posx - m->cub.pdx, \
		m->cub.posy - m->cub.pdy) == FALSE)
	{
			m->cub.posx -= m->cub.pdx;
			m->cub.posy -= m->cub.pdy;
			++(*count);
	}
}

void	map(t_master *m)
{
	void	*img;
	void	*img2;
	double	tmpx;
	double	tmpy;

	tmpx = (m->cub.posx * BLOCK_SIZE);
	tmpy = (m->cub.posy * BLOCK_SIZE);
	img = mlx_xpm_file_to_image(m->cub.mlx, PLAYER, &m->map.img_width, \
		&m->map.img_height);
	img2 = mlx_xpm_file_to_image(m->cub.mlx, VIEW, &m->map.img_width, \
		&m->map.img_height);
	mlx_clear_window(m->cub.mlx, m->cub.win);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->ceiling->img_ptr, 0, 0);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, \
		m->floor->img_ptr, 0, MAP_HEIGHT / 2);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->wall->img_ptr, 0, 0);
	create_map(m);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, img, tmpx, tmpy);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, img2, tmpx + \
		(BLOCK_SIZE * 1.1) * cos(m->cub.angle), \
		tmpy + (BLOCK_SIZE * 1.1) * sin(m->cub.angle));
}

void	rotate(t_master *m, int *count)
{
	if (m->key.rot_right)
	{
		m->cub.angle += ANGLE;
		if (m->cub.angle >= M_PI * 2)
			m->cub.angle -= M_PI * 2;
		m->cub.pdx = cos(m->cub.angle) * SPEED;
		m->cub.pdy = sin(m->cub.angle) * SPEED;
		++(*count);
	}
	if (m->key.rot_left)
	{
		m->cub.angle -= ANGLE;
		if (m->cub.angle < 0)
			m->cub.angle += M_PI * 2;
		m->cub.pdx = cos(m->cub.angle) * SPEED;
		m->cub.pdy = sin(m->cub.angle) * SPEED;
		++(*count);
	}
}

int	actions(t_master *m)
{
	int	count;

	map(m);
	count = 0;
	if (m->key.up)
		move_char(m, FORWARD, &count);
	if (m->key.down)
		move_char(m, BACKWARD, &count);
	if (m->key.left)
		move_char2(m, LEFT, &count);
	if (m->key.right)
		move_char2(m, RIGHT, &count);
	rotate(m, &count);
	if (count > 0)
	{
		wall_reset(m);
		raycast(m);
	}
	return (0);
}
