/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/24 07:22:37 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"

# define TRUE 1
# define FALSE 0

# define BLOCK_SIZE 32
# define MAP_WIDTH 1920
# define MAP_HEIGHT 1080

# define RAYCAST 500
# define FOV 90
# define SPEED 10
# define ANGLE 5

# define FORWARD 1
# define BACKWARD 2
# define LEFT 3
# define RIGHT 4

//KEYCODES
# define KEY_UP_W 13
# define KEY_DOWN_S 1
# define KEY_LEFT_A 0
# define KEY_RIGHT_D 2
# define KEY_ESC 53
# define KEY_ROT_LEFT 123
# define KEY_ROT_RIGHT 124

/* 
	Key struct for key press and release
	up:			// W
	down:		// S
	left:		// A
	right:		// D
	rot_left:	// left arrow
	rot_right:	// right arrow
 */

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rot_left;
	int	rot_right;
}	t_key;

/* 
	struct for the map part of the project
	**layout:	// map layout
	height:		// map height
	posx:		// initial player position x
	posy:		// initial player position y
	direction:	// initial view N, S, E, W
 */
typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_colour;
	char	*ceiling_colour;
	char	**layout;
	int		height;
	int		posx;
	int		posy;
	char	direction;
}	t_map;

/* 
	struct for the game part of the project
	posx:		// player position x
	posy:		// player position y
	angle:		// player view angle
*/
typedef struct s_cub
{
	void	*mlx;
	void	*win;
	int		floor_hex;
	int		ceil_hex;
	float	posx;
	float	posy;
	float	angle;
}	t_cub;

typedef struct s_img
{
	void	*ceiling_img;
	char	*ceiling;
	int		c_bpp;
	int		c_endian;
	int		c_line;
	void	*floor_img;
	char	*floor;
	int		f_bpp;
	int		f_endian;
	int		f_line;
	void	*halo;
	void	*wheel;
	char	*up_path;
	char	*left_path;
	char	*right_path;
	int		w;
	int		h;
	void	*wall_img;
	char	*wall;
	int		w_bpp;
	int		w_endian;
	int		w_line;
}	t_img;

// typedef struct s_img
// {
// 	void	*reference;
// 	char	*address;
// 	int		bpp;
// 	int		endian;
// 	int		line_size;
// }

// typedef struct s_sprites
// {
// 	t_img	screen;
// 	t_img	halo;
// 	t_img	wheel;
// }		t_sprites;

/* 
	struct for the master struct
	cub:		// game struct
	map:		// map struct
	key:		// key struct
	tmpx:		// temporary x
	tmpy:		// temporary y
 */
typedef struct s_master
{
	t_cub	cub;
	t_map	map;
	t_key	key;
	t_img	img;
	int		tmpx;
	int		tmpy;
}	t_master;


/* GAME_INIT */
void	game(t_master *m);

/* GAME_RUN */

/* GAME_UTIL */
float	 deg_to_rad(float degree);

/* MAIN */
int		map_init(t_master *m, char *file);
void	free_funct(char **array);
void	exit_err(t_master *m, char *message, int code);
int		close_window(t_master *m);

/* MAP_CHECK */
int		map_check(t_master *m);

/* MAP_HANDLE */
void	map_assign(t_master *m, char *file);
void	map_size(t_master *m, char *file);

/* MAP_UTIL */
int		create_trgb(int t, int r, int g, int b);

/* FREE */
void	free_funct(char **array);
void	exit_free(t_master *master);
void	init_map_vars(t_master *m);

/* GAME CONTROLLER */
void	key_init(t_master *m);
int		key_press(int keycode, t_master *m);
int		key_release(int keycode, t_master *m);
int		actions(t_master *m);
void raycast(t_master *m);
void draw_line_according_to_distance(t_master *m, float distance, int x);
#endif