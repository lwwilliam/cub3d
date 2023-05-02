/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:19:45 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 21:34:15 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The ft_memchr() function locates the first occurrence of c (converted to an
**	unsigned char) in string s.
**
**	The ft_memchr() function returns a pointer to the byte located, or NULL if no
**	such byte exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;

	a = (unsigned char)c;
	while (n-- != 0)
	{
		if (*(unsigned char *)s == a)
			return ((void *)s);
			++s;
	}
	return (NULL);
}
