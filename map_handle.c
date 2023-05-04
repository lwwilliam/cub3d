/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:56:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/05/03 17:16:52 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	identifier_check(t_map *map, char *id)
{
	if (!ft_strncmp(id, "NO", 2))
		map->north_texture = ft_substr(id, 3, ft_strlen(id) - 4);
	else if (!ft_strncmp(id, "SO", 2))
		map->south_texture = ft_substr(id, 3, ft_strlen(id) - 4);
	else if (!ft_strncmp(id, "WE", 2))
		map->west_texture = ft_substr(id, 3, ft_strlen(id) - 4);
	else if (!ft_strncmp(id, "EA", 2))
		map->east_texture = ft_substr(id, 3, ft_strlen(id) - 4);
	else if (!ft_strncmp(id, "F", 1))
		map->floor_colour = ft_substr(id, 2, ft_strlen(id) - 3);
	else if (!ft_strncmp(id, "C", 1))
		map->ceilling_colour = ft_substr(id, 2, ft_strlen(id) - 3);
}

void	map_size(t_map *map, char *file)
{
	int		line_no;
	char	*line;
	int		fd;

	line_no = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_err(map, "Error\nFile failed to open\n", 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line_no < 8)
			identifier_check(map, line);
		free(line);
		line_no++;
	}
	map->map = ft_calloc((line_no - 8) + 1, sizeof(char *));
	close(fd);
}

static void	assign_help(t_map *map, char *line)
{
	if (ft_strchr(line, '\t'))
	{
		free(line);
		exit_err(map, "Error\nTab is found\n", 1);
	}
	if (ft_strlen(line) > 1)
	{
		map->map[map->map_height] = ft_strtrim(line, "\n");
		map->map_height++;
	}
}

void	map_assign(t_map *map, char *file)
{
	char	*line;
	int		x;
	int		fd;

	x = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_err(map, "Error\nFile failed to open\n", 1);
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
		assign_help(map, line);
		free(line);
	}
	close(fd);
}
