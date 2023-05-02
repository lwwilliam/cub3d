/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/05/02 16:17:38 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game_vars(t_cub *cub, t_map *map)
{
	cub->posx = (long double)map->map_posx * (long double)BLOCK_SIZE;
	cub->posy = (long double)map->map_posy * (long double)BLOCK_SIZE;
}

void	game(t_map *map)
{
	t_cub	cub;

	init_game_vars(&cub, map);
	printf("final pos:\nposx:%Lf | posy:%Lf\n", cub.posx, cub.posy);
}
