/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:55:32 by lwilliam          #+#    #+#             */
/*   Updated: 2023/04/25 22:50:13 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 1000
// # include "../so_long.h"

char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *s);
char	*ft_strchr_gnl(const char *str, int y);
size_t	ft_strlen_gnl(const char *str);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		read_funct(int fd, char **buffer, int *x);
void	free_funct_gnl(char **str);

#endif