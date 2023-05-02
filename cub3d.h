/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/02 16:05:34 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
// # include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft_gnl/libft.h"
# include "./libft_gnl/gnl/get_next_line.h"

# define BLOCK_SIZE 32
# define TRUE 1
# define FALSE 0
# define MAP_WIDTH 1920
# define MAP_HEIGHT 1080

typedef struct s_map
{
	//identifiers ->>
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_colour;
	char	*ceilling_colour;
	// <<- identifiers
	int		posx;
	int		posy;
	char	**map;
	int		map_height;
}	t_map;


// struct for the game part of the project
typedef struct s_cub
{
	long double	posx;
	long double	posy;
}	t_cub;

//map initialize
int		map_size(t_map *map, int fd);
int		map_init(t_map *map, char *file);
int		map_check(t_map *map);
int		map_assign(t_map *map, int fd);
void	init_map_vars(t_map *map);

void	free_funct(char **array);

//game
void	game(t_map *map);


#endif