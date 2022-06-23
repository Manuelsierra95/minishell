# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:59:23 by msierra-          #+#    #+#              #
#    Updated: 2022/06/23 18:13:32 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	minishell
LIBFT_NAME  =	libft.a

INTERFACE	=	utils
MAP			=	map_create map_utils
CD			=	cd get_cd
ECHO		=	echo get_echo
ENV			=	env get_env
EXIT		=	exit get_exit
EXPORT		=	export get_export
PWD			=	pwd get_pwd
UNSET		=	unset get_unset
UTILS		=	isnum getenv is_in_env sort_env free isspecial isalpha_edit shell_loop print_info
LEXER		= 	tokenizer checkCmd get_path quote_manage get_input
PARSER 		= 	parser
ERRORS		=	errors
EXPANDER 	= 	expander 
EXEC    	=	exe_cmd exe builtin exe_pipes
REDIR		= 	redir

SRCS	=	$(addsuffix .c, $(addprefix sources/errors/, $(ERRORS))) 				\
			$(addsuffix .c, $(addprefix sources/utils/, $(UTILS))) 					\
			$(addsuffix .c, $(addprefix sources/lexer/, $(LEXER))) 					\
			$(addsuffix .c, $(addprefix sources/executor/, $(EXEC)))     			\
			$(addsuffix .c, $(addprefix sources/parser/, $(PARSER))) 				\
			$(addsuffix .c, $(addprefix sources/expander/, $(EXPANDER))) 			\
			$(addsuffix .c, $(addprefix sources/interface/, $(INTERFACE))) 			\
			$(addsuffix .c, $(addprefix sources/interface/map_builder/, $(MAP)))	\
			$(addsuffix .c, $(addprefix sources/builtins/cd/, $(CD))) 				\
			$(addsuffix .c, $(addprefix sources/builtins/echo/, $(ECHO))) 			\
			$(addsuffix .c, $(addprefix sources/builtins/env/, $(ENV))) 			\
			$(addsuffix .c, $(addprefix sources/builtins/exit/, $(EXIT))) 			\
			$(addsuffix .c, $(addprefix sources/builtins/export/, $(EXPORT)))		\
			$(addsuffix .c, $(addprefix sources/builtins/pwd/, $(PWD))) 			\
			$(addsuffix .c, $(addprefix sources/builtins/unset/, $(UNSET))) 		\
			$(addsuffix .c, $(addprefix sources/redir/, $(REDIR))) 		\
			main.c

FOLDERS = 	./includes/ ./libft/ ./sources/interface/ ./sources/interface/map_builder/ 	\
			./sources/builtins/echo/ ./sources/builtins/env/ 							\
			./sources/builtins/exit/ ./sources/builtins/export/ 						\
			./sources/builtins/pwd/ ./sources/builtins/unset/							\
 			./sources/builtins/cd/														\


INCLUDE_HEADERS = $(addprefix -I, $(FOLDERS))

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

# INCLUDES =	-I ./includes/ -I ./libft/ -I ./sources/builtins/interface/ -I ./sources/builtins/interface/builtins/cd

LIBFT	=	-L libft/ -lft

all	:		$(NAME)

$(NAME)	:	$(LIBFT_DIR)$(LIBFT_NAME) $(OBJS) bender
			@$(CC) $(CFLAGS) $(INCLUDE_HEADERS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
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
