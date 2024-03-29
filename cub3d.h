/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/08/11 14:49:04 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/includes/get_next_line.h"
# include "./libft/includes/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL "./xpm/wall32x32.xpm"
# define PLAYER "./xpm/test.xpm"
# define VIEW "./xpm/yes.xpm"

# define TRUE 1
# define FALSE 0
# define ERROR 2

# define BLOCK_SIZE 32
# define MAP_WIDTH 1920
# define MAP_HEIGHT 1080

# define RAYCAST 1920
# define FOV 60
# define SPEED 0.2
# define ANGLE 0.15
# define DOF 25

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define FORWARD 1
# define BACKWARD 2
# define LEFT 3
# define RIGHT 4

// KEYCODES
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
	int		up;
	int		down;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
}			t_key;

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
}			t_map;

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
	double	posx;
	double	posy;
	double	pdx;
	double	pdy;
	double	angle;
	char	*up_path;
	char	*left_path;
	char	*right_path;
}			t_cub;

typedef struct s_img
{
	void	*img_ptr;
	char	*img;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
}	t_img;

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
	t_img	*ceiling;
	t_img	*floor;
	t_img	*wall;
	t_img	*north;
	t_img	*east;
	t_img	*south;
	t_img	*west;
	t_img	*halo;
	t_img	*wheel;
	int		tmpx;	
	int		tmpy;
}			t_master;

typedef struct s_ray
{
	double	rayx;
	double	rayy;
	double	dist_hori;
	double	dist_verti;
	double	stepx;
	double	stepy;
	int		east_west;
	int		north_south;
	double	scale_hori;
	double	scale_verti;
	double	mapp;
	double	atan;
	double	angle;
	double	final_dist;
	double	final_scale;
	int		final_side;
	int		dof;
	int		i;
	char	*pixel;
	char	*pixel2;

	int		tmp;
	int		tmp2;
	int		x;
	int		y;
}			t_ray;

/* GAME_INIT */
void		game(t_master *m);

/* GAME_RUN */

/* GAME_UTIL */
double		deg_to_rad(double degree);

/* MAIN */
int			map_init(t_master *m, char *file);
void		free_funct(char **array);
void		exit_err(t_master *m, char *message, int code);
int			close_window(t_master *m);

/* MAP_CHECK */
int			map_check(t_master *m);

/* MAP_HANDLE */
void		map_assign(t_master *m, char *file);
void		map_size(t_master *m, char *file);

/* MAP_UTIL */
int			create_trgb(int t, int r, int g, int b);

int			create_map(t_master *m);

/* FREE */
void		free_funct(char **array);
void		exit_free(t_master *master);
void		init_map_vars(t_master *m);

/* GAME CONTROLLER */
int			actions(t_master *m);

/* KEY ACTIONS*/
void		key_init(t_master *m);
int			key_press(int keycode, t_master *m);
int			key_release(int keycode, t_master *m);

/* GAME RUN */
double		fisheye(t_master *m, t_ray *ray, double i);
double		get_dist(double ax, double ay, double bx, double by);
int			is_wall(t_master *m, int x, int y);
void		init_hori(t_master *m, t_ray *ray);
void		run_hori(t_master *m, t_ray *ray);
void		init_verti(t_master *m, t_ray *ray);
void		run_verti(t_master *m, t_ray *ray);
void		assign_final(t_master *m, t_ray *ray);

/* RENDER / RAYCAST*/
void		raycast(t_master *m);
void		rendering(t_ray *ray, t_master *m);
void		wall_reset(t_master *m);
void		wall_print(t_ray *ray, t_master *m);
void		wall_print2(t_ray *ray, t_master *m);

/* IMAGE INIT */
void		init_images(t_master *m);
void		wall_init(t_master *m);
void		init_cockpit(t_master *m);

#endif