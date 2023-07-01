/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:03:27 by wting             #+#    #+#             */
/*   Updated: 2023/06/08 13:27:26 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double degree)
{
	double	ret;

	ret = degree * M_PI / 180;
	return (ret);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
