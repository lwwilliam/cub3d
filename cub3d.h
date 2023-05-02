/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/02 15:41:33 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <unistd.h>
// # include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"

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
	char	**map;
	int		map_height;
}	t_map;

/* MAIN */
int		map_init(t_map *map, char *file);
void	free_funct(char **array);

/* MAP_CHECK */
int		map_check(t_map *map);

/* MAP_HANDLE */
int		map_assign(t_map *map, int fd);
int		map_size(t_map *map, int fd);
#endif