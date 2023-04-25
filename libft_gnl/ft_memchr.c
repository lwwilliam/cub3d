/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:14:37 by lwilliam          #+#    #+#             */
/*   Updated: 2022/05/24 18:47:51 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	x;
	char	*d;
	char	b;

	x = 0;
	d = (char *)str;
	b = (char)c;
	while (x < n)
	{
		if (*d == b)
		{
			return (d);
		}
		d++;
		x++;
	}
	return (0);
}
