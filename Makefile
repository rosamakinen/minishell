# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 11:03:29 by yoonslee          #+#    #+#              #
#    Updated: 2023/08/22 10:21:54 by rmakinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

BUILD_FLAGS = -Wall -Wextra -Werror -g

SRC := src/hashmap/add_hashmap.c \
		src/hashmap/clear_hashmap.c \
		src/hashmap/utils_hashmap.c \
		src/env/init_env.c \
		src/env/env.c\
		src/common/file_checker.c \
		src/common/greetings.c \
		src/common/file.c \
		src/common/pipe.c \
		src/common/redirection.c \
		src/common/save_exit_status.c \
		src/common/signal.c \
		src/common/pid.c \
		src/common/shlvl.c \
		src/common/executer.c \
		src/common/free.c \
		src/lexer/lexer.c \
		src/lexer/lexer_utils.c \
		src/lexer/char_checks.c \
		src/lexer/syntax_error.c \
		src/lexer/add_lines_lexer.c \
		src/command/concatenate_struct.c \
		src/command/init_command.c \
		src/command/redir_command.c \
		src/command/add_command.c \
		src/command/input_command.c \
		src/command/full_command.c \
		src/command/flags_command.c \
		src/command/heredoc_command.c \
		src/parser/expand_env.c \
		src/parser/expand_env_utils.c \
		src/parser/parser_utils.c \
		src/parser/concatenate.c \
		src/parser/parser_special.c \
		src/builtins/export.c \
		src/builtins/echo.c \
		src/builtins/cd.c \
		src/builtins/heredoc.c \
		src/builtins/heredoc_expand.c \
		src/builtins/pwd.c \
		src/builtins/execve.c \
		src/builtins/unset.c \
		src/builtins/exit.c \
		main.c \

OBJ := add_hashmap.o \
		clear_hashmap.o \
		utils_hashmap.o \
		init_env.o \
		env.o \
		file_checker.o \
		file.o \
		pipe.o \
		redirection.o \
		save_exit_status.o \
		signal.o \
		pid.o \
		shlvl.o \
		executer.o \
		free.o \
		lexer.o \
		lexer_utils.o \
		char_checks.o \
		syntax_error.o \
		add_lines_lexer.o \
		init_command.o \
		redir_command.o \
		add_command.o \
		input_command.o \
		full_command.o \
		flags_command.o \
		heredoc_command.o \
		expand_env.o \
		parser_utils.o \
		concatenate.o \
		parser_special.o \
		export.o \
		echo.o \
		cd.o \
		heredoc.o \
		heredoc_expand.o \
		pwd.o \
		execve.o \
		unset.o \
		exit.o \
		main.o \
		concatenate_struct.o \
		expand_env_utils.o \
		greetings.o \

HEADERS = headers/hashmap.h, headers/lexer.h, headers/minishell.h, headers/parsing.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	cc -o $(NAME) -Llibft -lft -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include $(BUILD_FLAGS) $(OBJ)

$(OBJ): $(SRC)
	cc -c -I libft -I ~/.brew/opt/readline/include $(BUILD_FLAGS) $(SRC)

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
