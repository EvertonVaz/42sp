# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 19:13:08 by egeraldo          #+#    #+#              #
#    Updated: 2023/07/18 18:37:59 by egeraldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

SRC = ../ft_*.c tests.c

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(SRC)
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f a.out
	rm -f libft

re: fclean all