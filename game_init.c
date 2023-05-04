/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:15 by wting             #+#    #+#             */
/*   Updated: 2023/05/04 17:42:29 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game_vars(t_master *m)
{
	m->cub.posx = (long double)m->map.posx * (long double)BLOCK_SIZE;
	m->cub.posy = (long double)m->map.posy * (long double)BLOCK_SIZE;
}

void	game(t_master *m)
{
	init_game_vars(m);
}
