# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/02 19:37:56 by afogonca          #+#    #+#              #
#    Updated: 2026/01/02 20:33:53 by afogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
RM=rm -fr
MAKE=make -C

LIBFT=libft/libft.a

SRCS=$(addprefix srcs/, main.c ft_data.c ft_lista.c)
OBJS=$(SRCS:.c=.o)

all: $(NAME)

get_libft:
	@if [ ! -d libft ]; then \
		git clone https://github.com/AfonsoMota-132/42_libft.git libft; \
	fi
	$(MAKE) libft

$(NAME): get_libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) libft

re: fclean all

.PHONY: all get_libft clean fclean re

