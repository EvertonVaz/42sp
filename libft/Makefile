# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 19:13:08 by egeraldo          #+#    #+#              #
#    Updated: 2023/07/28 14:31:16 by egeraldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

M_SRC = ft_atoi.c     ft_isalpha.c  ft_memchr.c   ft_memset.c   ft_strlcpy.c \
	ft_strrch.c   ft_bzero.c    ft_isascii.c  ft_memcmp.c   ft_strchr.c \
	ft_strlen.c   ft_tolower.c  ft_calloc.c   ft_isdigit.c  ft_memcpy.c \
	ft_strdup.c   ft_strncmp.c  ft_toupper.c  ft_isalnum.c  ft_isprint.c \
	ft_memmove.c  ft_strlcat.c  ft_strnstr.c  ft_substr.c   ft_strjoin.c \
	ft_strtrim.c  ft_split.c    ft_itoa.c     ft_strmapi.c  ft_striteri.c \
	ft_putchar_fd.c  ft_putstr_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c

M_OBJ = $(M_SRC:%.c=%.o)

B_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c

B_OBJ = $(B_SRC:%.c=%.o)

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(M_OBJ)
	ar -rcs $(NAME) $(M_OBJ)

bonus: $(NAME) $(B_OBJ)
	ar -rcs $(NAME) $(B_OBJ)

%.o: %.c
	cc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY:		all clean fclean re bonus