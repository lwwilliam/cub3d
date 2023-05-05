/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/05 14:52:59 by wting            ###   ########.fr       */
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
# define SPEED 4
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

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_key;

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_colour;
	char	*ceilling_colour;
	char	**layout;
	int		height;
	int		posx;
	int		posy;
	char	direction;
}	t_map;

// struct for the game part of the project
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

typedef struct s_master
{
	t_cub	cub;
	t_map	map;
	t_key	key;
}	t_master;

/* GAME_INIT */
void	game(t_master *m);

/* GAME_RUN */
void	move_char(t_master *master, int direction);

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

#endif