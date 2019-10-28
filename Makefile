# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlange <jlange@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 12:33:38 by jlange            #+#    #+#              #
#    Updated: 2019/10/28 10:17:23 by jlange           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all, clean, fclean, re

SRC_PATH = srcs

OBJ_PATH = objs

NAME = ft_select

CC = cc

HEADER = include/ft_select.h

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -Iinclude

SRC_NAME =  main.c \
			init_term.c \
			singleton.c \
			read.c \
			init_layout.c \
			init_params.c \
			calc_layout.c \
			print_args.c \
			arrow_actions.c \
			actions.c \
			tools.c \
			signals.c \
			set_colors.c \
			exit.c

OBJ = $(SRC_NAME:.c=.o)

OBJS = $(addprefix objs/, $(OBJ))

all: $(NAME)

$(NAME): objs/ $(OBJS)
	@$(CC) $(OBJS) libft/libft.a -ltermcap -lncurses -o $(NAME)

objs/:
	@make -C libft
	@mkdir $(OBJ_PATH) 2> /dev/null

objs/%.o: srcs/%.c $(HEADER)
	@$(CC) -Ilibft/includes -o $@ $(CPPFLAGS) -c $< $(CFLAGS)

clean:
	@make clean -C libft
	@rm -rf $(OBJ_PATH)

fclean:
	@make fclean -C libft
	@rm -rf $(NAME) $(OBJ_PATH) $(NAME)

re: fclean all
