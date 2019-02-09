# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 15:20:54 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/02/08 19:17:46 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# PATHS TO C SOURCE FILES
SRC_PATH = $(wildcard $(SRC_DIR)/*.c)
SRC_PATH += get_next_line/get_next_line.c

# PATHS TO OBJECTS
OBJ_PATH = $(SRC_PATH:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# PATH TO LIBFT
LIB_NAME = get_next_line/libft/libft.a
LIB_PATH = get_next_line/libft
LIB = -lft

# MLX INFO
MLX = -lmlx -framework OpenGL -framework AppKit

# COMPILATION RULES
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fdf

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_PATH) $(LIB_PATH)/$(LIB_NAME)
	$(CC) $(FLAGS) $(OBJ_PATH) -o $@ -I$(INC_DIR) -I$(LIB_PATH)/$(INC_DIR) -L$(LIB_PATH) $(LIB) $(MLX) 

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -o $@ -c $< -I$(INC_DIR) -I$(LIB_PATH)/$(INC_DIR)

$(LIB_PATH)/$(LIB_NAME):
	make -C $(LIB_PATH)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all