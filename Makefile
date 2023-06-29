# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 11:16:26 by mherrezu          #+#    #+#              #
#    Updated: 2023/06/21 13:20:16 by mherrezu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
MLX	= ./MLX42
PRINT_LIBFT	= ./print_libft
GNL	= ./get_next_line

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NORMI = norminette .

HEADERS	= -I ./includes -I ${MLX}/include -I ${PRINT_LIBFT} -I ${GNL}
GL	= -Iinclude -lglfw -L"/Users/mherrezu/.brew/opt/glfw/lib/"
LIBS	= ${GL} ${MLX}/libmlx42.a ${PRINT_LIBFT}/libft.a ${GNL}/getnextline.a
SRCS	= main.c basic_map_check.c compl_map_check.c

OBJS	= ${SRCS:.c=.o}


all: libft mlx gnl ${NAME}

libft:
	@$(MAKE) -C ${PRINT_LIBFT}
	@echo "Print_Libft compiled successfully\n"

gnl:
	@${MAKE} -C ${GNL}
	@echo "GNL compiled successfully\n"
	
mlx:
	@${MAKE} -C ${MLX}
	@echo "MLX42 compiled successfully\n"

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${PRINT_LIBFT} clean
	@${MAKE} -C ${MLX} clean
	@${MAKE} -C ${GNL} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${PRINT_LIBFT} fclean
	@${MAKE} -C ${MLX} fclean
	@${MAKE} -C ${GNL} fclean
	
re: clean all

.PHONY: all, clean, fclean, re, mlx, libft