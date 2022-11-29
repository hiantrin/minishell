# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 20:12:40 by mouarsas          #+#    #+#              #
#    Updated: 2022/11/09 22:24:52 by mouarsas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIB = libft/libft.a

SRCS = 	minishell.c\
		mini1.c\
		myshell.c\
		mini2.c\
		make_home.c \
		replace_with_env.c\
		getpath.c\
		create_env.c \
		help_all.c\
		and_and.c\
		one_for_all.c\
		one_for_all2.c\
		mini_stock.c\
		mini_stock1.c\
		help_redirections.c\
		help.c\
		mini_help.c\
		parsing_the_re.c\
		pipe_help.c\
		pipe.c\
		qoute_slash.c\
		redirect.c\
		strsplit.c\
		trait_and.c\
		trait_the_and.c\
		system.c\
		mini_qoute.c\
		builtins/cd.c\
		builtins/cd_norm.c\
		builtins/echo.c\
		builtins/env.c\
		builtins/exit.c\
		builtins/export.c\
		builtins/pwd.c\
		builtins/unset.c\
		help_to_norme.c\


CFLAGS := -Wall -Wextra -Werror
LFLAGS="-L/Users/mouarsas/.brew/opt/readline/lib"
IFLAGS="-I/Users/mouarsas/.brew/opt/readline/include"

CC = cc
OBJS :=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS) 
	@$(CC) $(CFLAGS) $^ -o $@ libft/libft.a $(FLAGS) -lreadline -lncurses $(LFLAGS)

%.o: %.c minishell.h 
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIB):
	@make -C libft

clean:
	@make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
