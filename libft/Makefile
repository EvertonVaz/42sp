# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 19:13:08 by egeraldo          #+#    #+#              #
#    Updated: 2023/07/19 19:00:26 by egeraldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c     ft_isalpha.c  ft_memchr.c   ft_memset.c   ft_strlcpy.c  ft_strrch.c \
ft_bzero.c    ft_isascii.c  ft_memcmp.c   ft_strchr.c   ft_strlen.c   ft_tolower.c \
ft_calloc.c   ft_isdigit.c  ft_memcpy.c   ft_strdup.c   ft_strncmp.c  ft_toupper.c \
ft_isalnum.c  ft_isprint.c  ft_memmove.c  ft_strlcat.c  ft_strnstr.c 

OBJ = $(SRC:%.c=%.o)

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re