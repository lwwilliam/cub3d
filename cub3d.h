/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/04 15:29:58 by lchew            ###   ########.fr       */
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
# define MAP_WIDTH 1920
# define MAP_HEIGHT 1080

//KEYCODES
# define KEY_UP_W 13
# define KEY_DOWN_S 1
# define KEY_LEFT_A 0
# define KEY_RIGHT_D 2
# define KEY_ESC 53

typedef struct s_keys
{
	int	key_up;
	int	key_down;
	int	key_left;
	int	key_right;
}			t_keys;

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_colour;
	char	*ceilling_colour;
	char	**map;
	int		map_height;
	int		map_posx;
	int		map_posy;
}	t_map;

// struct for the game part of the project
typedef struct s_cub
{
	void		*mlx;
	void		*win;
	long double	posx;
	long double	posy;
	t_keys		keys;
}	t_cub;

/* GAME_INIT */
void	game(t_map *map, t_cub *cub);

/* MAIN */
int		map_init(t_map *map, char *file);
void	free_funct(char **array);
void	exit_err(t_map *map, char *message, int code);
void	close_window(t_cub *cub, t_map *map);

/* MAP_CHECK */
int		map_check(t_map *map);

/* MAP_HANDLE */
void	map_assign(t_map *map, char *file);
void	map_size(t_map *map, char *file);

/* MAP_UTIL */
void	init_map_vars(t_map *map);

#endif