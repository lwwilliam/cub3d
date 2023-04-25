/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:54:25 by lwilliam          #+#    #+#             */
/*   Updated: 2023/04/25 22:50:13 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(const char *s)
{
	int		x;
	int		len;
	char	*str;

	x = 0;
	len = 0;
	while (s[x] != '\0')
	{
		len++;
		x++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	x = 0;
	while (s[x])
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strchr_gnl(const char *str, int y)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == (char)y)
		{
			return ((char *)str + x);
		}
		x++;
	}
	if (str[x] == (char)y)
	{
		return ((char *)str + x);
	}
	return (NULL);
}

size_t	ft_strlen_gnl(const char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*str;

	x = 0;
	if (!s)
		return (NULL);
	if (ft_strlen_gnl(s) <= start)
		return (ft_strdup_gnl(""));
	else if ((start + len) >= ft_strlen_gnl(s))
		len = ft_strlen_gnl(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (x < len)
	{
		str[x] = s[start];
		x++;
		start++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!str)
		return (0);
	while (s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	return (str);
}
