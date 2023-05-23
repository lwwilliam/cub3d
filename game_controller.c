/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:58 by lchew             #+#    #+#             */
/*   Updated: 2023/05/23 18:40:06 by yalee            ###   ########.fr       */
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

void	draw_line_according_to_distance(t_master *m, float distance, int x)
{
	int	i;
	char *pixel;

	i = 0;
	pixel = 
	while (i < 108)
	{
		
	}
}

// set a dummy pos_x and pos_y to imitate the position of the player.
// added a camera on the player position to simulate fov while ensuring that
// the screen does not move around while raycasting.
// the logic is to cast a ray from the line representing the leftmost fov, extend it 
// until it hits a wall, calculate the distance from the player to it and then render the wall
// according to that value. Repeat until the last ray, which is the rightmost line on the fov.
// since the true north of our project is 0 degrees, the leftmost ray would be angle - 45 and angle + 45 
// for the rightmost ray.

// the ray extends using the same logic as the movement. Which is the speed constant scaled by the
// trigonometric functions to extend it on a certain direction.
void	raycast(t_master *m)
{
	float	distance;
	float	camera_angle;
	float	dummy_posx;
	float	dummy_posy;
	int		x_for_window;
	
	x_for_window = 0;
	dummy_posx = m->cub.posx;
	dummy_posy = m->cub.posy;
	camera_angle = m->cub.angle - 45;
	while (camera_angle < m->cub.angle + 45)
	{
		dummy_posx = m->cub.posx;
		dummy_posy = m->cub.posy;
		while (m->map.layout[(int)(dummy_posy + cos(deg_to_rad(m->cub.angle)) * (SPEED * -1)) / 32][(int)(dummy_posx + sin(deg_to_rad(m->cub.angle)) * (SPEED)) / 32] != '1')
		{
			// same as
			// if (direction == FORWARD && m->map.layout[(int)(m->cub.posy + cos(deg_to_rad(m->cub.angle)) * (SPEED * -1)) / 32][(int)(m->cub.posx + sin(deg_to_rad(m->cub.angle)) * (SPEED)) / 32] != '1')
			// {
			// 	m->cub.posx += sin(deg_to_rad(m->cub.angle)) * (SPEED);
			// 	m->cub.posy += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
			// }
			dummy_posx += sin(deg_to_rad(m->cub.angle)) * (SPEED);
			dummy_posy += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
			distance += SPEED;
		}
		// will draw a straight line of different colour
		draw_line_according_to_distance(m, distance, x_for_window);
		// 90 / 1920
		camera_angle += 0.046875;
		x_for_window++;
	}
}

// added a map physics where player cant move trough walls
static void	move_char(t_master *m, int direction)
{
	if (direction == FORWARD && m->map.layout[(int)(m->cub.posy + cos(deg_to_rad(m->cub.angle)) * (SPEED * -1)) / 32][(int)(m->cub.posx + sin(deg_to_rad(m->cub.angle)) * (SPEED)) / 32] != '1')
	{
		m->cub.posx += sin(deg_to_rad(m->cub.angle)) * (SPEED);
		m->cub.posy += cos(deg_to_rad(m->cub.angle)) * (SPEED * -1);
	}
	else if (direction == BACKWARD && m->map.layout[(int)(m->cub.posy + cos(deg_to_rad(m->cub.angle)) * (SPEED)) / 32][(int)(m->cub.posx + sin(deg_to_rad(m->cub.angle)) * (SPEED * -1)) / 32] != '1')
	{
		m->cub.posx += sin(deg_to_rad(m->cub.angle)) * (SPEED * -1);
		m->cub.posy += cos(deg_to_rad(m->cub.angle)) * (SPEED);
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
