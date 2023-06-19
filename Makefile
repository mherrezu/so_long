# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariah. <mariah.@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 11:16:26 by mherrezu          #+#    #+#              #
#    Updated: 2023/06/19 17:50:45 by mariah.          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
MLX	= ./MLX42
LIBFT	= ./libft
PRINTF	= ./ft_printf
GNL	= ./get_next_line

HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBGN} -I ${LIBPF}
GNL	= -lglfw -L"/Users/erigolon/.brew/opt/glfw/lib"
LIBS	= ${GNL} ${MLX}/libmlx42.a ${LIBFT}/libft.a ${PRINTF}/libftprintf.a ${GNL}/get_next_line.a
SRCS	= main.c map_utils.c

OBJS	= ${SRCS:.c=.o}

# //= Recipes =//

all: libft mlx printf gnl ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

mlx:
	@${MAKE} -C ${MLX}

printf:
	@${MAKE} -C ${PRINTF}

gnl:
	@${MAKE} -C ${GNL}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${DFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${MLX} clean
	@${MAKE} -C ${PRINTF} clean
	@${MAKE} -C ${GNL} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${MLX} fclean
	@${MAKE} -C ${PRINTF} fclean
	@${MAKE} -C ${GNL} fclean
	
re: clean all

.PHONY: all, clean, fclean, re, mlx, libft