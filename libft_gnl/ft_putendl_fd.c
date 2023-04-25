/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:31:41 by lwilliam          #+#    #+#             */
/*   Updated: 2022/05/30 11:27:38 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	x;

	x = 0;
	if (!s)
		return ;
	while (s[x] != '\0')
	{
		write(fd, &s[x], 1);
		x++;
	}
	write(fd, "\n", 1);
}
