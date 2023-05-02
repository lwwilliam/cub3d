/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:36:46 by lchew             #+#    #+#             */
/*   Updated: 2022/05/23 20:36:46 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The ft_tolower() takes in the ASCII value of lowercase alphabetical character
**	and converts it to upper case. If not lowercase alphabet, it returns c.
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
