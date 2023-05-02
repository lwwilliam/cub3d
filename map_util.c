/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:18:04 by wting             #+#    #+#             */
/*   Updated: 2023/05/02 19:29:30 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_vars(t_map *map)
{
	map->north_texture = "";
	map->south_texture = "";
	map->west_texture = "";
	map->east_texture = "";
	map->floor_colour = "";
	map->ceilling_colour = "";
	map->direction = 0;
}
