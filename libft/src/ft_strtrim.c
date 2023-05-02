/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:59:10 by lchew             #+#    #+#             */
/*   Updated: 2022/06/02 16:21:32 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates with ft_calloc and returns a copy of 's1' with the characters
**	specified in 'set' removed from the beginning and the end of string.
**	
**	The ft_substr() returns the pointer to the new string.
**	Returns NULL if the allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*array;
	size_t			slen;
	unsigned int	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	slen = ft_strlen(s1);
	i = 0;
	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
	{
		++s1;
		--slen;
	}
	while (slen > 0 && ft_strrchr(set, s1[slen - 1]) != NULL)
		--slen;
	array = ft_calloc((slen + 1), sizeof(char));
	if (!array)
		return (NULL);
	ft_strlcpy(array, s1, slen + 1);
	return (array);
}
