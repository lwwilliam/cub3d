/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:11:46 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 21:11:46 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The ft_isprint() function tests for any printing character, including  
**	space (' '). character between 0 and octal 0177 inclusive.
**
**	The ft_isprint() function returns zero if the character tests false and 
**	returns non-zero if the character tests true.
*/

int	ft_isprint(int c)
{
	return (c >= 0040 && c <= 0176);
}
