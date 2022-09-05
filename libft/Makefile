# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 13:24:29 by hugrene           #+#    #+#              #
#    Updated: 2022/07/04 13:25:22 by hugrene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_PATH = ./obj/

SRC_NAME=	ft_split.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnstr.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	-@norminette *.c
	-@norminette *.h

.PHONY: all clean fclean re norm
