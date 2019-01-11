# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 15:20:54 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/01/11 15:57:06 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = test.c map_reader.c get_next_line/get_next_line.c get_next_line/libft/libft.a
LIB = minilibx/

NAME = fdf

all: $(NAME)

$(NAME):
	gcc test.c map_reader.c move.c zoom.c draw_wire.c begin.c get_next_line/get_next_line.c fdf.h get_next_line/libft/libft.a -lm -lmlx -lXext -lX11 -L minilibx/

clean:
	rm rf $(NAME)
