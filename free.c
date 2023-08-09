/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:41:21 by lwilliam          #+#    #+#             */
/*   Updated: 2023/08/09 17:29:11 by lwilliam         ###   ########.fr       */
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
	free(master->ceiling);
	free(master->floor);
	free(master->wall);
	free(master->north);
	free(master->east);
	free(master->south);
	free(master->west);
	system("leaks cub3d");
	exit(0);
}
