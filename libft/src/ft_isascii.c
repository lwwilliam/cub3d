/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:11:21 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 21:11:21 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The ft_isascii() function tests for an ASCII character, which is any 
**	character between 0 and octal 0177 inclusive.
**
**	The ft_isascii() function returns zero if the character tests false and 
**	returns non-zero if the character tests true.
*/

int	ft_isascii(int c)
{
	return (c >= 0000 && c <= 0177);
}
