# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchew <lchew@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 17:13:24 by lchew             #+#    #+#              #
#    Updated: 2022/05/14 22:01:24 by lchew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# MANDATORY
SRC_DIR = ./src/
SRC = $(addprefix ft_, $(addsuffix .c, \
		isalpha isdigit isalnum isascii isprint toupper tolower \
		memset memcpy memmove memchr memcmp atoi bzero calloc\
		strlen strlcpy strlcat strncmp strchr strrchr strnstr strdup \
		substr strjoin strtrim split itoa itoa_base strmapi striteri \
		putchar_fd putstr_fd putendl_fd putnbr_fd )) get_next_line.c
OBJ_DIR = ./obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

# BONUS
B_SRC = $(addprefix $(SRC_DIR)ft_, $(addsuffix .c, \
		lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
		lstclear lstiter lstmap))
B_OBJ = $(B_SRC:%.c=$(OBJ_DIR)%.o)

# HEADER
INC = ./includes
HEAD = -I$(INC)

# COMPILER
#-L ../libft -l ft<-- make the lib file dir able to be accessed anywhere
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(HEAD)

# LIBRARY
LIBCR = ar -rcs

# REMOVE FILES OR DIRECTORIES
RM = rm -f
RMDIR = rmdir

# PRETTY
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ printf "\n$(_SUCCESS) Libft object files generated.\n"
	@ @ printf "$(_INFO) Generating Libft Library...\n"
	@ $(LIBCR) $(NAME) $(OBJ)
	@ printf "$(_SUCCESS) Library created!\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) $(CFLAGS) $(HEAD) -c $< -o $@
	@ printf "$(YELLOW)$<$(RESET)... "

$(OBJ_DIR):
	@ printf "$(_INFO) Creating Libft object directory...\n"
	@ mkdir -p $(OBJ_DIR)
	@ printf "$(_SUCCESS) Libft object directory created.\n"
	@ printf "$(_INFO) Generating Libft object files...\n"

bonus: $(B_OBJ) $(OBJ)
	$(LIBCR) $(NAME) $(B_OBJ) $(OBJ)
	
clean:
	@ $(RM) $(OBJ) ${B_OBJ}
	@ $(RMDIR) $(OBJ_DIR)
	@ printf "$(_INFO) Libft object files & directory removed.\n"

fclean: clean
	@ $(RM) $(NAME)
	@ printf "$(_INFO) Libft cache cleared.\n"

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(B_SRC) ./libft.h

.PHONY: all clean fclean re norme bonus
