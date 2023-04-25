/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:14:46 by lwilliam          #+#    #+#             */
/*   Updated: 2022/05/27 11:46:47 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	x;
	char	*d;
	char	*s;

	x = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (x < len)
	{
		d[x] = s[x];
		x++;
	}
	return (dest);
}
