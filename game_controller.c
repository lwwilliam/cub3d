/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:58 by lchew             #+#    #+#             */
/*   Updated: 2023/05/10 17:04:45 by lchew            ###   ########.fr       */
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

//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED

static void	move_char(t_master *m, int direction)
{
	float	x;
	float	y;

	x = m->cub.posx;
	y = m->cub.posy;
	if (direction == FORWARD)
	{
		x += cos(deg_to_rad(m->cub.angle)) * (SPEED);
		y += sin(deg_to_rad(m->cub.angle)) * (SPEED);
		if (m->map.grid[(int)y / BLOCK_SIZE][(int)x / BLOCK_SIZE] != '1')
		{
			m->cub.posx = x;
			m->cub.posy = y;
		}
	}
	else if (direction == BACKWARD)
	{
		x += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		y += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		if (m->map.grid[(int)y / BLOCK_SIZE][(int)x / BLOCK_SIZE] != '1')
		{
			m->cub.posx = x;
			m->cub.posy = y;
		}
	}
	else if (direction == LEFT)
	{
		x += sin(deg_to_rad(m->cub.angle)) * (SPEED);
		y += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		if (m->map.grid[(int)y / BLOCK_SIZE][(int)x / BLOCK_SIZE] != '1')
		{
			m->cub.posx = x;
			m->cub.posy = y;
		}
	}
	else if (direction == RIGHT)
	{
		x += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		y += cos(deg_to_rad(m->cub.angle)) * (SPEED);
		if (m->map.grid[(int)y / BLOCK_SIZE][(int)x / BLOCK_SIZE] != '1')
		{
			m->cub.posx = x;
			m->cub.posy = y;
		}
	}
	else
		return ;
	printf("posx:%f | posy:%f | angle:%f\n", m->cub.posx, m->cub.posy, m->cub.angle);
}

int	actions(t_master *m)
{
	void	*img;
	void	*img2;
	float	tmpx;
	float	tmpy;

	tmpx = m->cub.posx;
	tmpy = m->cub.posy;
	tmpx += (BLOCK_SIZE * 1.1) * cos(deg_to_rad(m->cub.angle));
	tmpy += (BLOCK_SIZE * 1.1) * sin(deg_to_rad(m->cub.angle));
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	img = mlx_xpm_file_to_image(m->cub.mlx, PLAYER, &m->map.img_width, &m->map.img_height);
	img2 = mlx_xpm_file_to_image(m->cub.mlx, VIEW, &m->map.img_width, &m->map.img_height);
	mlx_clear_window(m->cub.mlx, m->cub.win);
	create_map(m);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, img, m->cub.posx, m->cub.posy);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, img2, tmpx, tmpy);
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
	if (m->key.rot_left)
	{
		m->cub.angle -= ANGLE;
	}
	if (m->key.rot_right)
	{
		m->cub.angle += ANGLE;
	}
	// usleep(20000);
	
	return (0);
}
