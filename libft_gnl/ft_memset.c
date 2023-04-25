/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:14:56 by lwilliam          #+#    #+#             */
/*   Updated: 2022/05/26 14:54:53 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			x;
	unsigned char	*p;

	x = 0;
	p = (unsigned char *)str;
	while (x < n)
	{
		p[x] = (unsigned char)c;
		x++;
	}
	return (p);
}
