/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:18:04 by wting             #+#    #+#             */
/*   Updated: 2023/05/05 14:55:26 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_vars(t_master *m)
{
	m->map.north_texture = NULL;
	m->map.south_texture = NULL;
	m->map.west_texture = NULL;
	m->map.east_texture = NULL;
	m->map.floor_colour = NULL;
	m->map.ceilling_colour = NULL;
	m->map.layout = NULL;
	m->map.height = 0;
	m->map.posx = 0;
	m->map.posy = 0;
}
