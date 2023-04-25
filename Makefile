# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 15:25:11 by lwilliam          #+#    #+#              #
#    Updated: 2023/04/26 02:06:07 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = main.c map_handle.c free.c map_check.c
		
GCC = gcc 

# CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft_gnl/libft.a

all : $(NAME)

$(NAME): $(SRC)
	make -C libft_gnl
	$(GCC) $(CFLAGS) $(SRC) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	rm -f *.o
	make clean -C libft_gnl

fclean : clean
	rm -f $(NAME)
	make fclean -C libft_gnl
	
re: fclean all
	make re -C libft_gnl