NAME = libftprintf.a

CC = cc

FLAGS = -g3 -Wall -Wextra -Werror

SRC =	./mandatory/ft_printf.c \
		./mandatory/ft_printf_utils.c \
		./mandatory/ft_put_pointer.c \
		./mandatory/ft_putnbr_base.c \

OBJECTS = $(SRC:%.c=%.o)

SRC_B =	./bonus/ft_printf_bonus.c \
		./bonus/ft_lens_bonus.c \
		./bonus/ft_puts_bonus.c \
		./bonus/ft_strings_bonus.c \
		./bonus/ft_width_bonus.c \


OBJECTS_B = $(SRC_B:%.c=%.o)

INCLUDES = ./mandatory/ft_printf.h

INCLUDES_B = ./bonus/ft_printf_bonus.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)

bonus: $(OBJECTS_B)

%.o:%.c $(INCLUDES) $(INCLUDES_B)
	${CC} ${FLAGS} -c $< -o $@
	ar rc $(NAME) $@

clean:
	$(RM) $(OBJECTS) $(OBJECTS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
