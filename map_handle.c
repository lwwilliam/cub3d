/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:56:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/04/26 03:36:58 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	colour(t_map *map, char *id)
{
	if (!ft_strncmp(id, "F", 1))
	{
		map->floor_colour = ft_substr(id, 2, ft_strlen(id) - 3);
		return (0);
	}
	else if (!ft_strncmp(id, "C", 1))
	{
		map->ceilling_colour = ft_substr(id, 2, ft_strlen(id) - 3);
		return (0);
	}
	return (1);
}

int	identifier_check(t_map *map, char *id)
{
	if (!ft_strncmp(id, "NO", 2))
	{
		map->north_texture = ft_substr(id, 3, ft_strlen(id) - 4);
		return (0);
	}
	else if (!ft_strncmp(id, "SO", 2))
	{
		map->south_texture = ft_substr(id, 3, ft_strlen(id) - 4);
		return (0);
	}
	else if (!ft_strncmp(id, "WE", 2))
	{
		map->west_texture = ft_substr(id, 3, ft_strlen(id) - 4);
		return (0);
	}
	else if (!ft_strncmp(id, "EA", 2))
	{
		map->east_texture = ft_substr(id, 3, ft_strlen(id) - 4);
		return (0);
	}
	else if (colour(map, id) == 1)
		return (1);
	return (0);
}

int	map_size(t_map *map, int fd)
{
	int		width;
	int		height;
	char	*line;

	width = 0;
	height = 0;
	map->north_texture = "";
	map->south_texture = "";
	map->west_texture = "";
	map->east_texture = "";
	map->floor_colour = "";
	map->ceilling_colour = "";
	while (1)
	{
		line = get_next_line(fd);
		if (height < 8)
			identifier_check(map, line);
		if (line == NULL)
			break ;
		if (width < ft_strlen(line))
			width = ft_strlen(line);
		free(line);
		height++;
	}
	map->map = ft_calloc((height - 8) + 1, sizeof(char *));
	return (0);
}

int	assign_help(t_map *map, char *line)
{
	if (ft_strchr(line, '\t'))
	{
		ft_putstr_fd("\033[0;31mError!\nTabs is found\033[0m\n", 2);
		return (1);
	}
	if (ft_strlen(line) > 1)
	{
		map->map[map->map_height] = ft_strtrim(line, "\n");
		map->map_height++;
	}
	return (0);
}

int	map_assign(t_map *map, int fd)
{
	char	*line;
	int		x;

	x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (x < 8)
		{
			x++;
			free(line);
			continue ;
		}
		if (assign_help(map, line) == 1)
			return (1);
		free(line);
	}
	return (0);
}
