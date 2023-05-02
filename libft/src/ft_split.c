/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:19:41 by lchew             #+#    #+#             */
/*   Updated: 2022/06/03 14:28:38 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Count the number of strings separated by separators.
Return the strings' count.*/
static int	countstr(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			++count;
			while (*s != '\0' && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

/*Count number of characters of string seperated by separatr.
Return the characters' count.*/
static int	countchar(char const *s, char c)
{
	int	countchar;

	countchar = 0;
	while (*s != '\0' && *s++ != c)
		++countchar;
	return (countchar);
}

/*Allocate with ft_calloc memory for each strings.  
Return i which is the last pointer in 'res' array for NULL terminating.*/
static unsigned int	putstr(char const *s, char c, char **res)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (*s != '\0')
	{
		j = 0;
		if (*s != c)
		{
			res[i] = ft_calloc((countchar(s, c) + 1), sizeof(char));
			while (*s != c && *s)
				res[i][j++] = *s++;
			res[i++][j] = '\0';
		}
		else
			++s;
	}
	return (i);
}

/*If failed Malloc to res, return NULL.
If str argument is empty, return NULL res.
Otherwise, duplicate str to first string in array res.
Array res is then NULL terminated.*/
static char	**emptyc(char const *str, char **res)
{
	int	i;
	int	j;

	i = 0;
	while (*(str + i))
		i++;
	j = 0;
	res[0] = ft_calloc((i + 1), sizeof(char));
	while (*str)
		res[0][j++] = *str++;
	res[0][j] = '\0';
	res[1] = 0;
	return (res);
}

/*
**	Allocates with ft_calloc and returns an array of strings obtained by
**	splitting 's' using the character 'c' as a delimiter. The array must end
**	with a NULL pointer
**	
**	The ft_split() returns the array of new strings resulting from the split.
**	Returns NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c)
{
	char	**res;

	if (s == NULL)
		return (NULL);
	res = ft_calloc((countstr(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	if (*s == '\0')
		return (res);
	if (c == '\0')
		return (emptyc(s, res));
	res[putstr(s, c, res)] = NULL;
	return (res);
}
