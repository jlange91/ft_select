# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 17:18:13 by thdelmas          #+#    #+#              #
#    Updated: 2019/10/22 18:05:55 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_select
PROJECT := FT_SELECT
AUTHORS := Thdelmas

RM = /bin/rm

### Directories ###
SRC_DIR := ./sources
INC_DIR := ./headers
OBJ_DIR := ./.obj

### SUB FILES ###
SUB_DIRS := \


### INCLUDE SRC MAKEFILE ###
include $(SRC_DIR)/sources.mk

### INCLUDE INC MAKEFILE ###
include $(INC_DIR)/headers.mk


### ALL SUB DIRS ###
SRC_SUB_DIRS = $(addprefix $(SRC_DIR)/,$(SUB_DIRS))
OBJ_SUB_DIRS = $(addprefix $(OBJ_DIR)/,$(SUB_DIRS))
INC_SUB_DIRS = $(addprefix $(INC_DIR)/,$(SUB_DIRS))


### MAIN AND SUB FILES ###
O_FILES = $(C_FILES:.c=.o)


### Full Paths ###
SRC = $(addprefix $(SRC_DIR)/,$(C_FILES))
OBJ = $(addprefix $(OBJ_DIR)/,$(O_FILES))
INC = $(addprefix $(INC_DIR)/,$(H_FILES))


### Lib ###
FT = ft
FT_DIR = ./lib$(FT)
FT_INC_DIR = $(FT_DIR)/includes
FT_LNK = -L$(FT_DIR) -l$(FT)

###  CC && FLAGS ###
CC = clang
DEBUG_FLAGS = -g3
CFLAGS = \
		 $(addprefix -I ,$(INC_DIR) $(INC_SUB_DIRS) $(FT_INC_DIR)) \
		 $(DEBUG_FLAGS) \
		 -Wall -Wextra -Werror

LFLAGS = -ltermcap \
		 -lncurses \
		 $(FT_LNK) \



.PHONY: all clean fclean re

all: $(FT) $(NAME)

### Lib compil ###
$(FT):
	@make -C $(FT_DIR)

$(SHUTIL): $(FT)
	@make -C $(SHUTIL_DIR)

### Mkdir obj ###
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_SUB_DIRS)

### Compilation ###
.ONESHELL:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

### Link ###
$(NAME): $(OBJ_DIR) $(OBJ) $(INC) Makefile $(FT_DIR)/libft.a
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

### Clean ###
$(FT)_clean:
	@make -C $(FT_DIR) clean

clean: $(FT)_clean $(SHUTIL)_clean
	$(RM) -rf $(OBJ_DIR)

$(FT)_fclean:
	@make -C $(FT_DIR) fclean

fclean: $(FT)_fclean
	$(RM) -rf $(OBJ_DIR)
	$(RM) -rf $(NAME).dSYM
	$(RM) -rf $(NAME)

re: fclean all

