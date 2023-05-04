/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:18:04 by wting             #+#    #+#             */
/*   Updated: 2023/05/04 17:43:24 by lchew            ###   ########.fr       */
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
