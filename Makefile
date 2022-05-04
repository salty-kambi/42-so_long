# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:06:54 by lsuau             #+#    #+#              #
#    Updated: 2021/11/30 14:43:03 by lsuau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEX = so_long

INC = so_long.h gnl/get_next_line.h

SRC = main.c map_parse.c map_check_error.c game_init.c move_it.c stock.c gnl/get_next_line.c gnl/get_next_line_utils.c

GCC = gcc #-Wall -Werror -Wextra -fsanitize=address

OBJS = ${SRC:.c=.o}

all : ${NAMEX}

%.o : %.c ${INC}
	${GCC} -Imlx -c $< -o $@

${NAMEX}: ${OBJS} ${INC}
	make -C mlx
	${GCC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAMEX}

clean :
	rm -f ${OBJS}

fclean : clean
	make -C mlx clean
	rm  -f ${NAMEX}

re : fclean all

.PHONY: bonus all clean fclean re
