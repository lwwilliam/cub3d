/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:05:21 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/04 23:02:30 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	resres(int e, int f)
{
	int	res;

	res = 0;
	if (f > e)
		res = 0;
	else
		res = e - f;
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		flen;
	int		elen;
	int		reslen;
	int		x;

	flen = 0;
	x = 0;
	if (!(s1) || !(set))
		return (NULL);
	elen = ft_strlen(s1);
	while (s1[flen] && ft_strchr(set, s1[flen]) != NULL)
		flen++;
	while (s1[elen - 1] && ft_strrchr(set, s1[elen - 1]) != NULL)
		elen--;
	reslen = resres(elen, flen);
	res = malloc(sizeof(char) * (reslen + 1));
	if (!(res))
		return (NULL);
	while (flen < elen)
		res[x++] = s1[flen++];
	res[x] = '\0';
	return (res);
}

// int main()
// {
// 	char *s1 = "111111";
// 	// printf("%s\n", ft_strtrim(s1, "1"));

// 	return (0);
// }