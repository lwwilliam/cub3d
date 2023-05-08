/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:58 by lchew             #+#    #+#             */
/*   Updated: 2023/05/05 19:24:31 by wting            ###   ########.fr       */
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

//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED

static void	move_char(t_master *m, int direction)
{
	if (direction == FORWARD)
	{
		m->cub.posx += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		m->cub.posy += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		// m->cub.posx += cos(deg_to_rad(m->cub.angle)) * SPEED;
		// m->cub.posy += sin(deg_to_rad(m->cub.angle)) * SPEED;
	}
	else if (direction == BACKWARD)
	{
		m->cub.posx += sin(deg_to_rad(m->cub.angle)) * SPEED;
		m->cub.posy += cos(deg_to_rad(m->cub.angle)) * SPEED;
		// m->cub.posx += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		// m->cub.posy += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
	}
	else if (direction == LEFT)
	{
		m->cub.posx += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		m->cub.posy += sin(deg_to_rad(m->cub.angle)) * SPEED;
	}
	else if (direction == RIGHT)
	{
		m->cub.posx += cos(deg_to_rad(m->cub.angle)) * SPEED;
		m->cub.posy += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
	}
}

int	actions(t_master *m)
{
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
	usleep(20000);
		printf("posx:%f | posy:%f | angle:%f\n", m->cub.posx, m->cub.posy, m->cub.angle);
	return (0);
}
