# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 15:20:54 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/01/23 17:11:57 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c map_reader.c move.c zoom.c draw_wire.c draw_figs.c temp_funcs.c funcs.c begin.c rotate.c get_next_line/get_next_line.c get_next_line/libft/libft.a

all: $(NAME)

$(NAME):
	gcc  $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all