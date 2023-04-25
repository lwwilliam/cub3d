/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:15:10 by lwilliam          #+#    #+#             */
/*   Updated: 2022/05/27 15:38:32 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t y)
{
	size_t	x;

	x = 0;
	if (y == 0)
	{
		while (src[x])
			x++;
		return (x);
	}
	while (src[x] != '\0' && x < y - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < y)
	{
		dest[x] = '\0';
	}
	while (src[x] != '\0')
		x++;
	return (x);
}
