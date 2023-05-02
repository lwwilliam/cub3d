/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:50:10 by lchew             #+#    #+#             */
/*   Updated: 2022/05/25 16:50:10 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
**	Allocates with ft_calloc and returns a substring from the string 's'.
**	The substring begins at index 'start' and is of maximum size 'len'.
**	
**	The ft_substr() returns the pointer to the index 'start' of the substring.
**	Returns NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	s += start;
	i = ft_strlen(s);
	if (i < len)
		len = i;
	sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}
