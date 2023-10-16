/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:09:00 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 22:28:44 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
**	The ft_strncmp() function compares null-terminated strings s1 and s2 up to 
**	not more than n characters.  Because ft_strncmp() is designed for comparing 
**	strings rather than binary data, characters that appear after a `\0' 
**	character are not compared.
**	
**	The ft_strcmp() and ft_strncmp() functions return an integer greater than,
**	equal to, or less than 0, according as the string s1 is greater than, equal 
**	to, or less than the string s2.  The comparison is done using unsigned 
**	characters, so that `\200' is greater than `\0'. 
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 1 && (*s1 != '\0' || *s2 != '\0') && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
