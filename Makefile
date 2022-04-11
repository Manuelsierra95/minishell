# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:59:23 by msierra-          #+#    #+#              #
#    Updated: 2022/04/11 18:14:05 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	minishell

BUILTINS	=	pwd exit env echo

UTILS		=	fd_tools atoi str_tools split

##LEXER##

SRCS		=	$(addsuffix .c, $(addprefix sources/builtins/, $(BUILTINS)))  \
					$(addsuffix .c, $(addprefix sources/utils/, $(UTILS)))	\
					main.c

PINK = \033[1;35m
GREEN = \033[1;32m
BLUE = \033[1;36m
RESET = \033[0m

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -rf

AR		= ar rcs

CFLAGS 	= -Wall -Werror -Wextra -I includes/

all	:		$(NAME)

$(NAME)	:	start $(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline
			@echo "$(RESET)Done"
			@echo "$(GREEN)==========WELLDONE==========$(RESET)"
			@echo "Success creating $(NAME) file"

start:		
			@echo "$(RESET)"
			@echo "─────────────────────────────"
			@echo "─────────────▐█▌─────────────"
			@echo "─────────────▐░▌─────────────"
			@echo "─────────────▐░▌─────────────"
			@echo "─────────────▐░▌─────────────"
			@echo "──────────▄▄▀░░░▀▄▄──────────"
			@echo "────────▄▀░░░░░░░░░▀▄────────"
			@echo "──────▄▀░░░░░░░░░░░░░▀▄──────"
			@echo "─────▐░░░░░░░░░░░░░░░░░▌─────"
			@echo "────▐░░░░░░░░░░░░░░░░░░░▌────"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌───"
			@echo "──▄███████████████████████▄──"
			@echo "─████▀────▀███████▀────▀███▄─"
			@echo "─███▀───────█████────────███─"
			@echo "─███───███───███───███───███─"
			@echo "─███───▀▀▀───███───▀▀▀───███─"
			@echo "─▀███▄─────▄█████▄─────▄███▀─"
			@echo "──▀███████████████████████▀──"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐░▄▀▀█▀▀█▀▀█▀▀█▀▀█▀▀▄░▌───"
			@echo "───▐░█▄▄█▄▄█▄▄█▄▄█▄▄█▄▄█░▌───$(BLUE) 	msierra- && mbarylak$(RESET)"
			@echo "───▐░█──█──█──█──█──█──█░▌───"
			@echo "───▐░█▀▀█▀▀█▀▀█▀▀█▀▀█▀▀█░▌───$(BLUE)	CREATING: $(GREEN)$(NAME)$(RESET)"
			@echo "───▐░▀▄▄█▄▄█▄▄█▄▄█▄▄█▄▄▀░▌───"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "───▐░░░░░░░░░░░░░░░░░░░░░▌───"
			@echo "────▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────"


%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:	
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
