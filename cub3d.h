/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/04/25 19:00:51 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft_gnl/libft.h"
# include "./libft_gnl/gnl/get_next_line.h"

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

//map initialize
int		colour(t_map *map, char *id);
int		identifier_check(t_map *map, char *id);
int		map_size(t_map *map, int fd);
int		map_init(t_map *map, char *file);
int		map_check(t_map *map);

void	free_funct(char **array);

#endif