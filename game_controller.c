/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:58 by lchew             #+#    #+#             */
/*   Updated: 2023/08/07 18:37:51 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_init(t_master *m)
{
	m->key.up = 0;
	m->key.down = 0;
	m->key.left = 0;
	m->key.right = 0;
	m->key.rot_left = 0;
	m->key.rot_right = 0;
}

int	key_press(int keycode, t_master *m)
{
	if (keycode == KEY_UP_W)
		m->key.up = 1;
	else if (keycode == KEY_DOWN_S)
		m->key.down = 1;
	else if (keycode == KEY_LEFT_A)
		m->key.left = 1;
	else if (keycode == KEY_RIGHT_D)
		m->key.right = 1;
	else if (keycode == KEY_ROT_LEFT)
		m->key.rot_left = 1;
	else if (keycode == KEY_ROT_RIGHT)
		m->key.rot_right = 1;
	return (0);
}

int	key_release(int keycode, t_master *m)
{
	if (keycode == KEY_ESC)
		close_window(m);
	if (keycode == KEY_UP_W)
		m->key.up = 0;
	else if (keycode == KEY_DOWN_S)
		m->key.down = 0;
	else if (keycode == KEY_LEFT_A)
		m->key.left = 0;
	else if (keycode == KEY_RIGHT_D)
		m->key.right = 0;
	else if (keycode == KEY_ROT_LEFT)
		m->key.rot_left = 0;
	else if (keycode == KEY_ROT_RIGHT)
		m->key.rot_right = 0;
	return (0);
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// posx = cos(angle) * SPEED
// pos𝑦 = sin(angle) * SPEED

static void	move_char(t_master *m, int direction)
{
	double	x;
	double	y;

	x = m->cub.posx;
	y = m->cub.posy;
	if (direction == FORWARD)
	{
		x += m->cub.pdx;
		y += m->cub.pdy;
		if (m->map.grid[(int)y][(int)x] != '1')
		{
			m->cub.posx = x;
			m->cub.posy = y;
		}
	}
	else if (direction == BACKWARD)
	{
		x -= m->cub.pdx;
		y -= m->cub.pdy;
		if (m->map.grid[(int)y][(int)x] != '1')
		{
			m->cub.posx = x;
			m->cub.posy = y;
		}
	}
	else if (direction == LEFT)
	{
		x += cos(m->cub.angle - (M_PI / 2)) * SPEED;
		y += sin(m->cub.angle - (M_PI / 2)) * SPEED;
		if (m->map.grid[(int)y][(int)x] != '1')
		{
			m->cub.posx = x;
			m->cub.posy = y;
		}
	}
	else if (direction == RIGHT)
	{
		x -= cos(m->cub.angle - (M_PI / 2)) * SPEED;
		y -= sin(m->cub.angle - (M_PI / 2)) * SPEED;
		if (m->map.grid[(int)y][(int)x] != '1')
		{
			m->cub.posx = x;
			m->cub.posy = y;
		}
	}
	else
		return ;
	wall_reset(m);
	raycast(m);
}

int	actions(t_master *m)
{
	void	*img;
	void	*img2;
	double	tmpx;
	double	tmpy;
	double	tmp2x;
	double	tmp2y;

	tmpx = (m->cub.posx * BLOCK_SIZE);
	tmpy = (m->cub.posy * BLOCK_SIZE);
	tmp2x = tmpx + (BLOCK_SIZE * 1.1) * cos(m->cub.angle);
	tmp2y = tmpy + (BLOCK_SIZE * 1.1) * sin(m->cub.angle);
	img = mlx_xpm_file_to_image(m->cub.mlx, PLAYER, &m->map.img_width, \
		&m->map.img_height);
	img2 = mlx_xpm_file_to_image(m->cub.mlx, VIEW, &m->map.img_width, \
		&m->map.img_height);
	mlx_clear_window(m->cub.mlx, m->cub.win);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->ceiling->img_ptr, 0, 0);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->floor->img_ptr, 0, MAP_HEIGHT / 2);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->wall->img_ptr, 0, 0);
	// mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->north->img_ptr, 0, 0);
	create_map(m);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, img, tmpx, tmpy);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, img2, tmp2x, tmp2y);
	if (m->key.up)
	{
		move_char(m, FORWARD);
	}
	if (m->key.down)
	{
		move_char(m, BACKWARD);
	}
	if (m->key.left)
	{
		move_char(m, LEFT);
	}
	if (m->key.right)
	{
		move_char(m, RIGHT);
	}
	if (m->key.rot_right)
	{
		m->cub.angle += ANGLE;
		if (m->cub.angle >= M_PI * 2)
			m->cub.angle -= M_PI * 2;
		m->cub.pdx = cos(m->cub.angle) * SPEED;
		m->cub.pdy = sin(m->cub.angle) * SPEED;
		wall_reset(m);
		raycast(m);
	}
	if (m->key.rot_left)
	{
		m->cub.angle -= ANGLE;
		if (m->cub.angle < 0)
			m->cub.angle += M_PI * 2;
		m->cub.pdx = cos(m->cub.angle) * SPEED;
		m->cub.pdy = sin(m->cub.angle) * SPEED;
		wall_reset(m);
		raycast(m);
	}
	return (0);
}
