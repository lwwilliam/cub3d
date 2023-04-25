/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:05:08 by lwilliam          #+#    #+#             */
/*   Updated: 2022/06/08 15:04:48 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s)
	{
		++count;
		++s;
	}
	return (count);
}

static int	getwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	a = malloc(sizeof(char *) * (getwords(s, c) + 1));
	if (!a)
		return (NULL);
	a[0] = NULL;
	while (*s)
	{
		if (countlen(s, c) != 0)
		{
			a[i] = ft_substr(s, 0, countlen(s, c));
			s += countlen(s, c);
			++i;
		}
		else
			++s;
	}
	a[i] = NULL;
	return (a);
}
