/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
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
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	s += len;
	if (c >= 256)
		c -= 256;
	while (len-- >= 0)
	{
		if (*s == c)
			return ((char *)s);
		--s;
	}
	return (NULL);
}
