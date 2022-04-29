# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:59:23 by msierra-          #+#    #+#              #
#    Updated: 2022/04/20 19:12:09 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	minishell
LIBFT_NAME  =	libft.a

BUILTINS	=	pwd exit env echo cd export unset
UTILS		=	isnum getenv is_in_env sort_env free isspecial isalpha_edit shell_loop
LEXER		= 	lexer checkCmd get_path quote_manage lexer_utils
PARSER 		= 	parser
ERRORS		=	errors

EXPANDER = 	expander 

SRCS	=	$(addsuffix .c, $(addprefix sources/builtins/, $(BUILTINS))) 	\
			$(addsuffix .c, $(addprefix sources/utils/, $(UTILS))) 			\
			$(addsuffix .c, $(addprefix sources/lexer/, $(LEXER))) 			\
			$(addsuffix .c, $(addprefix sources/parser/, $(PARSER))) 		\
			$(addsuffix .c, $(addprefix sources/expander/, $(EXPANDER))) 	\
			$(addsuffix .c, $(addprefix sources/errors/, $(ERRORS))) 	\
			main.c 

PINK = \033[1;35m
GREEN = \033[1;32m
BLUE = \033[1;36m
RESET = \033[0m

OBJS	= ${SRCS:.c=.o}

LIBFT_DIR	=	./libft/


CC		= gcc

RM		= rm -rf

AR		= ar rcs

CFLAGS 	= -Wall -Werror -Wextra -g3 #-fsanitize=address

INCLUDES =	-I ./includes/ -I ./libft/

LIBFT	=	-L libft/ -lft

all	:		$(NAME)

$(NAME)	:	$(LIBFT_DIR)$(LIBFT_NAME) $(OBJS) bender
			@$(CC) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
			@echo "$(RESET)Done"
			@echo "$(GREEN)==========WELLDONE==========$(RESET)"
			@echo "Success creating $(NAME) file"

bender:		
			@echo "$(RESET)"
			@echo "─────────────▐█▌─────────────"
			@echo "─────────────▐░▌─────────────"
			@echo "──────────▄▄▀░░░▀▄▄──────────"
			@echo "────────▄▀░░░░░░░░░▀▄────────"
			@echo "──────▄▀░░░░░░░░░░░░░▀▄──────"
			@echo "─────▐░░░░░░░░░░░░░░░░░▌─────"
			@echo "────▐░░░░░░░░░░░░░░░░░░░▌────"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌───"
			@echo "──▄███████████████████████▄──"
			@echo "─████▀────▀███████▀────▀███▄─"
			@echo "─███───███───███───███───███─"
			@echo "─▀███▄─────▄█████▄─────▄███▀─"
			@echo "──▀███████████████████████▀──"
			@echo "───▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌───"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐░▄▀▀█▀▀█▀▀█▀▀█▀▀█▀▀▄░▌───"
			@echo "───▐░█▄▄█▄▄█▄▄█▄▄█▄▄█▄▄█░▌───$(BLUE) 	msierra- && mbarylak$(RESET)"
			@echo "───▐░█▀▀█▀▀█▀▀█▀▀█▀▀█▀▀█░▌──────────────────────────"
			@echo "───▐░▀▄▄█▄▄█▄▄█▄▄█▄▄█▄▄▀░▌───$(BLUE)	CREATING: $(GREEN)$(NAME)$(RESET)"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "────▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────"


%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

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
