# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:59:23 by msierra-          #+#    #+#              #
#    Updated: 2025/02/21 20:54:01 by msierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	minishell
LIBFT_NAME  =	libft.a

GREEN = \033[1;32m
BLUE = \033[1;36m
RESET = \033[0m

FOLDERS = 	./libft/ ./include/ ./src/utils ./src/lexer ./src/parser ./src/executor

INCLUDE_HEADERS = $(addprefix -I, $(FOLDERS))

UTILS = init_shell
LEXER = index tokenizer
PARSER = index parse_pipeline
EXECUTOR = index

SRCS	= $(addsuffix .c, $(addprefix src/utils/, $(UTILS))) 				\
				$(addsuffix .c, $(addprefix src/lexer/, $(LEXER))) 				\
				$(addsuffix .c, $(addprefix src/parser/, $(PARSER))) 				\
				$(addsuffix .c, $(addprefix src/executor/, $(EXECUTOR))) 				\
				main.c

OBJS	= ${SRCS:.c=.o}

LIBFT_DIR	=	./libft/

CC		= gcc

RM		= rm -rf

AR		= ar rcs

CFLAGS 	= -Wall -Werror -Wextra -g3 #-fsanitize=address

LIBFT	=	-L libft/ -lft

all	:		folders_msg $(NAME)

$(NAME)	:	$(LIBFT_DIR)$(LIBFT_NAME) $(OBJS) msg
			@$(CC) $(CFLAGS) $(INCLUDE_HEADERS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
			@echo "$(RESET)Done"
			@echo "$(GREEN)Success creating $(NAME) file$(RESET)"
			@echo "───────────────────────────────────────"

folders_msg: 
			@echo "$(BLUE)Compiling folders: $(GREEN)$(FOLDERS)$(RESET)"

msg:		
			@echo "$(RESET)"
			@echo "$(BLUE) 	lcasabel && msierra-$(RESET)"
			@echo "───────────────────────────────────────"
			@echo "$(BLUE)	CREATING: $(GREEN)$(NAME)$(RESET)"
			@echo "───────────────────────────────────────"

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCLUDE_HEADERS) -o $@

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
			make -C $(LIBFT_DIR)

clean:	
			make -C $(LIBFT_DIR) clean
			$(RM) ${OBJS}

fclean:		clean
			make -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
