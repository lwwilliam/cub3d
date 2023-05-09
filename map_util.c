/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:18:04 by wting             #+#    #+#             */
/*   Updated: 2023/05/09 20:42:12 by lchew            ###   ########.fr       */
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
	m->map.ceiling_colour = NULL;
	m->map.grid = NULL;
	m->map.height = 0;
	m->map.posx = 0;
	m->map.posy = 0;
}
