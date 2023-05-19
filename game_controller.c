/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:58 by lchew             #+#    #+#             */
/*   Updated: 2023/05/19 22:14:06 by lwilliam         ###   ########.fr       */
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
	m->img.wheel = mlx_xpm_file_to_image(m->cub.mlx, m->img.up_path, &m->img.w, &m->img.h);
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
	int w;
	int	h;

	if (direction == FORWARD)
	{
		m->cub.posx += sin(deg_to_rad(m->cub.angle)) * (SPEED);
		m->cub.posy += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		// m->cub.posx += cos(deg_to_rad(m->cub.angle)) * SPEED;
		// m->cub.posy += sin(deg_to_rad(m->cub.angle)) * SPEED;
	}
	else if (direction == BACKWARD)
	{
		m->cub.posx += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		m->cub.posy += cos(deg_to_rad(m->cub.angle)) * (SPEED);
		// m->cub.posx += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		// m->cub.posy += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
	}
	else if (direction == LEFT)
	{
		m->cub.posx += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		m->cub.posy += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		m->img.wheel = mlx_xpm_file_to_image(m->cub.mlx, m->img.left_path, &w, &h);
	}
	else if (direction == RIGHT)
	{
		m->cub.posx += cos(deg_to_rad(m->cub.angle)) * SPEED;
		m->cub.posy += sin(deg_to_rad(m->cub.angle)) * (SPEED);
		m->img.wheel = mlx_xpm_file_to_image(m->cub.mlx, m->img.right_path, &w, &h);
	}
	else
		return ;
	printf("posx:%f | posy:%f | angle:%f\n", m->cub.posx, m->cub.posy, m->cub.angle);
}


int	actions(t_master *m)
{
	void	*img;
	void	*img2;
	char	*relative_path = "./xpm/test.xpm";
	char	*relative = "./xpm/yes.xpm";
	int		img_width;
	int		img_height;
	float	tmpx;
	float	tmpy;

	tmpx = m->cub.posx;
	tmpy = m->cub.posy;
	tmpx += (BLOCK_SIZE * 1.1) * sin(deg_to_rad(m->cub.angle)) + 24;
	tmpy += (BLOCK_SIZE * 1.1) * cos(deg_to_rad(m->cub.angle + 180)) + 24;
	img = mlx_xpm_file_to_image(m->cub.mlx, relative_path, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(m->cub.mlx, relative, &img_width, &img_height);
	mlx_clear_window(m->cub.mlx, m->cub.win);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->img.ceiling_img, 0, 0);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->img.floor_img, 0, MAP_HEIGHT / 2);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->img.halo, 0, 580);
	mlx_put_image_to_window(m->cub.mlx, m->cub.win, m->img.wheel, 573, 720);
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
