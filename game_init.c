/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/05/02 16:42:37 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game_vars(t_cub *cub, t_map *map)
{
	cub->posx = (long double)map->map_posx * (long double)BLOCK_SIZE;
	cub->posy = (long double)map->map_posy * (long double)BLOCK_SIZE;
}

void	game(t_map *map, t_cub *cub)
{
	init_game_vars(cub, map);
}
