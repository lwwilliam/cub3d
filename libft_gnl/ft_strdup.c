/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:15:13 by lwilliam          #+#    #+#             */
/*   Updated: 2022/05/30 11:21:39 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	int		x;
	int		len;
	char	*str;

	x = 0;
	len = 0;
	while (s[x] != '\0')
	{
		len++;
		x++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	x = 0;
	while (s[x])
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
