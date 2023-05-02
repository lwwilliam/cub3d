/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:05:22 by lchew             #+#    #+#             */
/*   Updated: 2022/05/24 20:15:47 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
**	The ft_memcmp() function compares byte string s1 against byte string s2.  
**	Both strings are assumed to be n bytes long.
**	
**	The ft_memcmp() function returns zero if the two strings are identical, other-
**	wise returns the difference between the first two differing bytes (treated
**	as unsigned char values, so that `\200' is greater than `\0', for example).
**	Zero-length strings are always identical.  
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 1 && (*(unsigned char *)s1 == *(unsigned char *)s2))
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
