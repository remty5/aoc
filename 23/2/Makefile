# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:53:36 by rvandepu          #+#    #+#              #
#    Updated: 2023/12/13 11:52:30 by remty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := day2

SRC  := $(NAME).c \

OBJ := $(SRC:%.c=%.o)

LIB_PATH := libft
LIB		 := libft.a

CPPFLAGS += -I$(LIB_PATH)
CFLAGS   += -Wall -Wextra
LDFLAGS  += -L$(LIB_PATH)
LDLIBS   += -lft

.PHONY: all clean fclean re test

all: $(LIB) $(NAME)

clean:
	$(RM) $(OBJ) tester

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

test: re
	./$(NAME) input

$(LIB):
	$(MAKE) -C $(LIB_PATH) $@

$(NAME): $(OBJ)
