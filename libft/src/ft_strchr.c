/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:01:55 by lchew             #+#    #+#             */
/*   Updated: 2022/05/23 21:01:55 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The ft_strchr() function returns a pointer to the first occurrence of the
**	character c in the string s.
**
**	The ft_strchr() functions returns NULL if the character is not found.
**
**	The terminating null byte is considered part of the string, so that if c
**	is specified as '\0', these functions return a pointer to the terminator.
*/
char	*ft_strchr(const char *s, int c)
{
	if (c >= 256)
		c -= 256;
	while (*s != '\0' && *s != c)
		++s;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
