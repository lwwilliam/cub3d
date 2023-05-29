/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/29 16:25:06 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <limits.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"

# define WALL "./xpm/wall32x32.xpm"
# define PLAYER "./xpm/test.xpm"
# define VIEW "./xpm/yes.xpm"

# define TRUE 1
# define FALSE 0

# define BLOCK_SIZE 32
# define MAP_WIDTH 1920
# define MAP_HEIGHT 1080

# define RAYCAST 60
# define FOV 60
# define SPEED 2
# define ANGLE 2

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
	**grid:	// map grid
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
	char	**grid;
	int		height;
	int		width;
	int		posx;
	int		posy;
	char	direction;
	int		img_width;
	int		img_height;
	char	*mini_wall;
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
	int		tmpx;
	int		tmpy;
}	t_master;

typedef struct s_coord
{
	float	x_float;
	float	y_float;
	int		x_int;
	int		y_int;
}	t_coord;

typedef struct s_vect
{
	t_coord	X;
	t_coord	Y;
	t_coord A;
	t_coord B;
}	t_vect;

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

int		create_map(t_master *m);

/* FREE */
void	free_funct(char **array);
void	exit_free(t_master *master);
void	init_map_vars(t_master *m);

/* GAME CONTROLLER */
void	key_init(t_master *m);
int		key_press(int keycode, t_master *m);
int		key_release(int keycode, t_master *m);
int		actions(t_master *m);

/* GAME RUN */
void	raycast(t_master *m);

#endif