/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:59:02 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 22:22:57 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
**	Allocates with ft_calloc and returns a new string, which is the result
**	of the concatenation of 's1' and 's2'.
**	
**	The ft_strjoin() returns the pointer to the new string.
**	Returns NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*array;
	size_t			len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	array = ft_calloc(len, sizeof(char));
	if (!array)
		return (NULL);
	ft_strlcpy(array, s1, len);
	ft_strlcat(array, s2, len);
	return (array);
}
