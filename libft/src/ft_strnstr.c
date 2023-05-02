/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:32:02 by lchew             #+#    #+#             */
/*   Updated: 2022/06/02 16:21:23 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The ft_strnstr() function locates the first occurrence of the null-terminated
**	string needle in the string haystack, where not more than len characters are
**	searched.  Characters that appear after a `\0' character are not searched.
**	
**	If needle is an empty string, haystack is returned; if needle occurs nowhere
**	in haystack, NULL is returned; otherwise a pointer to the first character of
**	the first occurrence of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;

	x = ft_strlen(needle);
	if (x == 0)
		return ((char *)haystack);
	while (len > 0 && *haystack != '\0')
	{
		if ((len >= x) && (ft_memcmp(haystack, needle, x) == 0))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
