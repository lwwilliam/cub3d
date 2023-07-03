/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:56:46 by lwilliam          #+#    #+#             */
/*   Updated: 2023/07/03 22:31:02 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	identifier_check(t_master *m, char *id)
{
	if (!ft_strncmp(id, "NO", 2))
		m->map.north_texture = ft_substr(id, 3, ft_strlen(id) - 4);
	else if (!ft_strncmp(id, "SO", 2))
		m->map.south_texture = ft_substr(id, 3, ft_strlen(id) - 4);
	else if (!ft_strncmp(id, "WE", 2))
		m->map.west_texture = ft_substr(id, 3, ft_strlen(id) - 4);
	else if (!ft_strncmp(id, "EA", 2))
		m->map.east_texture = ft_substr(id, 3, ft_strlen(id) - 4);
	else if (!ft_strncmp(id, "F", 1))
		m->map.floor_colour = ft_substr(id, 2, ft_strlen(id) - 3);
	else if (!ft_strncmp(id, "C", 1))
		m->map.ceiling_colour = ft_substr(id, 2, ft_strlen(id) - 3);
}

void	map_size(t_master *m, char *file)
{
	int		line_no;
	char	*line;
	int		fd;

	line_no = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_err(m, "Error\nFile failed to open\n", 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line_no < 8)
			identifier_check(m, line);
		free(line);
		line_no++;
	}
	m->map.grid = ft_calloc((line_no - 8) + 1, sizeof(char *));
	close(fd);
}

static void	assign_help(t_master *m, char *line)
{
	if (ft_strchr(line, '\t'))
	{
		free(line);
		exit_err(m, "Error\nTab is found\n", 1);
	}
	if (ft_strlen(line) > 1)
	{
		m->map.grid[m->map.height] = ft_strtrim(line, "\n");
		m->map.height++;
	}
}

void	map_assign(t_master *m, char *file)
{
	char	*line;
	int		x;
	int		fd;

	x = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_err(m, "Error\nFile failed to open\n", 1);
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
		assign_help(m, line);
		free(line);
	}
	m->map.grid[m->map.height] = NULL;
	close(fd);
}
