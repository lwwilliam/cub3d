/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:56:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/04/26 01:53:23 by lwilliam         ###   ########.fr       */
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
	char	*line;

	width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (map->map_height < 8)
			identifier_check(map, line);
		if (line == NULL)
			break ;
		if (width < ft_strlen(line))
			width = ft_strlen(line);
		free(line);
		map->map_height++;
	}
	map->map = ft_calloc((map->map_height - 8) + 1, sizeof(char *));
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
		if (ft_strchr(line, '\t'))
		{
			ft_putstr_fd("\033[0;31mError!\nTabs is found\033[0m\n", 2);
			return (1);
		}
		map->map[x - 8] = ft_substr(line, 0, ft_strlen(line) - 1);
		x++;
		free(line);
	}
	return (0);
}

int	map_init(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\033[0;31mError!\nInvalid File\033[0m\n", 2);
		return (1);
	}
	map->map_height = 0;
	if (map_size(map, fd) == 1)
		return (1);
	fd = open(file, O_RDONLY);
	if (map_assign(map, fd) == 1)
	{
		free_funct(map->map);
		return (1);
	}
	map->map_height -= 9;
	if (map_check(map) == 1)
	{
		free_funct(map->map);
		return (1);
	}
	return (0);
}

	// printf("%s\n", map->north_texture);
	// printf("%s\n", map->south_texture);
	// printf("%s\n", map->west_texture);
	// printf("%s\n", map->east_texture);
	// printf("%s\n", map->floor_colour);
	// printf("%s\n", map->ceilling_colour);