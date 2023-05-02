# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wting <wting@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 15:25:11 by lwilliam          #+#    #+#              #
#    Updated: 2023/05/02 15:47:58 by wting            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = main.c map_handle.c free.c map_check.c map_util.c game_init.c
		
GCC = gcc 

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft_gnl/libft.a

all : $(NAME)

$(NAME): $(SRC)
	make -C libft_gnl
	$(GCC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) #-fsanitize=address -g #-lmlx -framework OpenGL -framework AppKit

clean : 
	rm -f *.o
	make clean -C libft_gnl

fclean : clean
	rm -f $(NAME)
	make fclean -C libft_gnl
	
re: fclean all
	make re -C libft_gnl