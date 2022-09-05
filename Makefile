# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 13:27:43 by hugrene           #+#    #+#              #
#    Updated: 2022/07/04 13:28:29 by hugrene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
FLAGS	= -Wall -Wextra -Werror

NAME	= pipex

INCLUDE	= inc
LIBFT_PATH	= libft
SRC_PATH	= src
OBJ_PATH	= obj

SOURCES = main.c \
		utils.c \
		parsing.c

SRC	= $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ	= $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m


all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)libft..$(NOC)"
	@make -sC $(LIBFT_PATH)
	@$(CC) $(FLAGS) -L $(LIBFT_PATH) -o $@ $^ -lft
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(INCLUDE) -c -o $@ $<
	@echo "$(BLUE)clang $(WHITE)$(notdir $@)$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

norm:
	-@norminette $(SRC_PATH)
	-@norminette $(INCLUDE)

.PHONY:	all clean fclean re norm
