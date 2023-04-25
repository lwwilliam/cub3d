/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:15:26 by lwilliam          #+#    #+#             */
/*   Updated: 2022/05/27 14:52:05 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int y)
{
	int	lw;

	lw = 0;
	while (str[lw] != '\0')
	{
		lw++;
	}
	while (lw >= 0)
	{
		if (str[lw] == (char)y)
		{
			return ((char *)str + lw);
		}
		lw--;
	}
	return (0);
}
