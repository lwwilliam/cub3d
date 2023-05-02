/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:14:14 by lchew             #+#    #+#             */
/*   Updated: 2023/02/26 19:08:20 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	char		txtread[BUFFER_SIZE + 1];
	int			nbyte;
	static char	*buffer;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1)
		return (NULL);
	nbyte = read(fd, txtread, BUFFER_SIZE);
	if (nbyte <= 0 && (buffer == NULL || *buffer == '\0' ))
	{
		ft_free(&buffer);
		return (NULL);
	}
	buffer = gnl_find_nl(buffer, nbyte, txtread, fd);
	buffer = gnl_write(buffer, &res);
	return (res);
}

char	*gnl_find_nl(char *buffer, int nbyte, char *txtread, int fd)
{
	int	find_nl;
	int	i;

	find_nl = 0;
	while (find_nl != 1 && nbyte != 0)
	{
		txtread[nbyte] = '\0';
		if (buffer == NULL)
			buffer = ft_strdup(txtread);
		else
			buffer = gnl_join(buffer, txtread);
		i = 0;
		while (txtread[i] != '\0' && txtread[i] != '\n' && i < nbyte)
			++i;
		find_nl = (txtread[i] == '\n');
		if (find_nl != 1)
			nbyte = read(fd, txtread, BUFFER_SIZE);
		else
			nbyte = 0;
	}
	return (buffer);
}

char	*gnl_join(char *s1, char *s2)
{
	char			*array;
	size_t			len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	array = malloc(len * sizeof(char));
	if (!array)
		return (NULL);
	*array = '\0';
	ft_strlcpy(array, s1, len);
	ft_strlcat(array, s2, len);
	ft_free(&s1);
	return (array);
}

char	*gnl_write(char *buffer, char **res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		++i;
	i += (buffer[i] == '\n');
	*res = ft_substr(buffer, 0, i);
	tmp = ft_strdup(buffer + i);
	ft_free(&buffer);
	return (tmp);
}

void	ft_free(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}
