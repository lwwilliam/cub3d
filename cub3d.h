/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/02 18:19:25 by wting            ###   ########.fr       */
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

# define BLOCK_SIZE 32
# define TRUE 1
# define FALSE 0
# define MAP_WIDTH 1920
# define MAP_HEIGHT 1080
# define FOV 90
# define SPEED 2

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
	float	posx;
	float	posy;
	float	angle;
}	t_cub;

/* GAME_INIT */
void	game(t_map *map);

/* MAIN */
int		map_init(t_map *map, char *file);
void	free_funct(char **array);

/* MAP_CHECK */
int		map_check(t_map *map);

/* MAP_HANDLE */
int		map_assign(t_map *map, int fd);
int		map_size(t_map *map, int fd);

/* MAP_UTIL */
void	init_map_vars(t_map *map);

#endif