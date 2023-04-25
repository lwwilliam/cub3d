/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:48:02 by lwilliam          #+#    #+#             */
/*   Updated: 2022/05/27 14:53:41 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	x;
	size_t	dlen;
	size_t	slen;
	size_t	res;
	char	*s;

	x = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	s = (char *)src;
	if (nb > dlen)
		res = slen + dlen;
	else
		res = slen + nb;
	while (s[x] != '\0' && (dlen + 1) < nb)
	{
		dest[dlen] = src[x];
		dlen++;
		x++;
	}
	dest[dlen] = '\0';
	return (res);
}
