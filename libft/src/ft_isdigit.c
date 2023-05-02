/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:11:31 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 21:11:31 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The ft_isdigit() function tests for a decimal digit character.
**
**	The ft_isdigit() functions return zero if the character tests false and
**	return non-zero if the character tests true.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
