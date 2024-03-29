# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 15:25:11 by lwilliam          #+#    #+#              #
#    Updated: 2023/08/11 15:06:27 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name:
NAME	=	cub3d

# MANDATORY SOURCE CODE
SRC_DIR = ./
SRC		=	main.c map_handle.c free.c map_check.c map_util.c game_init.c \
			game_run.c game_util.c game_controller.c map_boundary.c wall_up.c \
			wall_down.c wall.c key_actions.c render_raycast.c
OBJ_DIR = ./obj/
OBJ		= $(SRC:%.c=$(OBJ_DIR)%.o)

# HEADER
INC_DIR = ./
INC		= -I$(INC_DIR)

# COMPILATION
CC			=	gcc
CFLAGS		=	$(FSAN) #-Wall -Wextra -Werror
FSAN		= 	-fsanitize=address -g

# LIBFT LIBRARY
LIBFT_DIR = ./libft/
LIBFT = libft.a
# -L "folder" to looks for library in the folder
# -l(ft) to link library file. l replaces lib
LIB := -L./libft -lft

# REMOVE FILES OR DIRECTORIES
RM = rm -f
RMDIR = rmdir

# PRETTY
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

OUTPUT = print.txt

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@ ${CC} $(CFLAGS) -Ilibft -lmlx -framework OpenGL -framework AppKit ${OBJ} ${LIB} -o $@
	@ printf "$(_SUCCESS) Window startup\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ printf "$(_INFO) Libft object directory created.\n"

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)
	
clean:
	@ $(RM) $(OBJ)
	@ printf "$(_INFO) Object files & directory removed.\n"

fclean: clean
	@ $(RM) $(NAME)
	@ $(RMDIR) $(OBJ_DIR)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ printf "$(_INFO) Window cache cleared.\n"

re: fclean all

.PHONY: all clean fclean re