/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/05/02 22:41:41 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


//posx = cos(angle) * SPEED
//pos𝑦 = sin(angle) * SPEED
static void	init_game_vars(t_cub *cub, t_map *map)
{
	cub->posx = (float)map->map_posx * (float)BLOCK_SIZE;
	cub->posy = (float)map->map_posy * (float)BLOCK_SIZE;
	printf("DIRECTION CHECK:%c\n", map->direction);
	if (map->direction == 'N')
		cub->angle = 0;
	else if (map->direction == 'S')
		cub->angle = 180;
	else if (map->direction == 'E')
		cub->angle = 90;
	else if (map->direction == 'W')
		cub->angle = 270;
}

void	game(t_map *map, t_cub *cub)
{
	init_game_vars(cub, map);	
}
