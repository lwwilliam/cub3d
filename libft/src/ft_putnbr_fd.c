/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:20:49 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 21:42:21 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Outputs the integer 'n' to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == INT_MIN)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n = n * -1;
	}
	while (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + '0', fd);
		n = -1;
	}
	if (n < 10 && n >= 0)
		ft_putchar_fd((n + '0'), fd);
}
