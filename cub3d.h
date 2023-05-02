/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/02 22:34:09 by wting            ###   ########.fr       */
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

# define BLOCK_SIZE 1
# define MAP_WIDTH 1920
# define MAP_HEIGHT 1080

# define RAYCAST 500
# define FOV 90
# define SPEED 0.25

# define FORWARD 1
# define BACKWARD 2
# define LEFT 3
# define RIGHT 4

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_colour;
	char	*ceilling_colour;
	int		map_posx;
	int		map_posy;
	char	**map;
	int		map_height;
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
	t_cub	*m_cub;
	t_map	*m_map;
}	t_master;

/* GAME_INIT */
void	game(t_map *map, t_cub *cub);

/* GAME_RUN */
void	move_char(t_master *master, int direction);

/* GAME_UTIL */
float	 deg_to_rad(float degree);

/* MAIN */
int		map_init(t_map *map, char *file);

/* MAP_CHECK */
int		map_check(t_map *map);

/* MAP_HANDLE */
int		map_assign(t_map *map, int fd);
int		map_size(t_map *map, int fd);

/* MAP_UTIL */
void	init_map_vars(t_map *map);
int		create_trgb(int t, int r, int g, int b);

/* FREE */
void	free_funct(char **array);
void	exit_free(t_master *master);

#endif