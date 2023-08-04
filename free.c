/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:41:21 by lwilliam          #+#    #+#             */
/*   Updated: 2023/08/04 14:40:17 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_funct(char **array)
{
	char	**tmp;

	tmp = array;
	while (tmp && *tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(array);
}

void	exit_free(t_master *master)
{
	free_funct(master->map.grid);
	ft_putendl_fd("keyboard interrupt", 2);
	exit(0);
}

int	is_wall(t_master *m, int x, int y)
{
	if (x < 0 || y < 0 || y >= m->map.height || x >= ft_strlen(m->map.grid[y]))
		return (FALSE);
	if (m->map.grid[y][x] == '1')
		return (TRUE);
	else
		return (FALSE);
}
