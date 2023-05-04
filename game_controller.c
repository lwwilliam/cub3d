/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:58 by lchew             #+#    #+#             */
/*   Updated: 2023/05/02 17:20:44 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_action(int keycode, t_cub *cub, t_map *map)
{
	if (keycode == KEY_ESC)
		close_window(cub, map);
	else if (keycode == KEY_UP_W)
		pos_swap(0, -1, cub);
	else if (keycode == KEY_DOWN_S)
		pos_swap(0, 1, cub);
	else if (keycode == KEY_LEFT_A)
		pos_swap(-1, 0, cub);
	else if (keycode == KEY_RIGHT_D)
		pos_swap(1, 0, cub);
	return (0);
}