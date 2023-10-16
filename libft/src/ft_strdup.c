/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:42:38 by lchew             #+#    #+#             */
/*   Updated: 2022/05/25 15:42:38 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
**	The ft_strdup() function returns a pointer to a new string a of which is 
**	a duplicate of the string s.
**	
**	The ft_strdup() function returns a pointer to the duplicated string.
**	It returns NULL if insufficient memory was available
*/
char	*ft_strdup(const char *src)
{
	char	*dup;
	char	*d;

	dup = ft_calloc((ft_strlen(src) + 1), sizeof(char));
	if (!dup)
		return (NULL);
	d = dup;
	while (*src != '\0')
		*d++ = *src++;
	*d = '\0';
	return (dup);
}
