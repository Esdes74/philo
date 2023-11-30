# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 16:40:33 by eslamber          #+#    #+#              #
#    Updated: 2023/11/30 11:36:47 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Definitions of variables
#

# Compilation flags
FLAGS := -Wall -Werror -Wextra
CC := gcc

#
### Definition of names variables
#

# Definition of LIB variables
LIB_DIR := libft/
LIB := $(LIB_DIR)libft.a

# Definition of project variables
NAME := philo
HEADER := philo.h

# Definition of files variables
SRC := main.c 
OBJ := $(SRC:%.c=.obj/%.o)

#
### Compilation rules
#

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ -L. $(LIB)

.obj/%.o: %.c $(HEADER) $(LIB)
	$(CC) $(FLAGS) -c $< -o $@

$(LIB): FORCE
	make -C $(LIB_DIR)

# Debug
debug:
	make -C libft debug
	make -C ./ "FLAGS = -Wall -Wextra -fsanitize=address \
	-fno-omit-frame-pointer -g3"

val_deb:
	make -C libft valgrind_deb
	make -C ./ "FLAGS = -Wall -Werror -Wextra -g3"

#
### Cleanup rules
#

clean:
	@rm -rfv $(OBJ)
	make -sC libft clean

fclean:
	@rm -rfv $(OBJ)
	@rm -rfv $(NAME)
	make -C libft fclean

re: fclean all

re_deb: fclean debug

re_val: fclean val_deb

.PHONY: all clean fclean re FORCE
