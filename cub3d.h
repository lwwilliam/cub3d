/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/04 17:55:32 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"

# define BLOCK_SIZE 32
# define TRUE 1
# define FALSE 0
# define MAP_WIDTH 200
# define MAP_HEIGHT 200

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
}	t_map;

// struct for the game part of the project
typedef struct s_cub
{
	void		*mlx;
	void		*win;
	long double	posx;
	long double	posy;
}	t_cub;

typedef struct s_master
{
	t_cub	cub;
	t_map	map;
	t_key	key;
}	t_master;

/* GAME_INIT */
void	game(t_master *m);

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
void	init_map_vars(t_master *m);

/* GAME CONTROLLER */
void	key_init(t_master *m);
int		key_press(int keycode, t_master *m);
int		key_release(int keycode, t_master *m);
int		actions(t_master *m);

#endif