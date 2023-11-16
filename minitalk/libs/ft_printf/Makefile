NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g3

# Path Definition
BIN_PATH = ./bin/
SRC_HEADER_PATH = ./src/ft_printf.h
SRC_SOURCES_PATH = ./src/

# Colors Definition
GREEN = "\033[32m"
RED = "\033[31m"
VIOLATE = "\033[38;5;208m"
COLOR_LIMITER = "\033[0m"

# Sources Definition
SOURCES = \
		ft_printf.c \
		ft_lens.c \
		ft_puts.c \
		ft_strings.c \
		ft_width.c \

# Objects Definition
OBJECTS = $(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))
all: $(BIN_PATH) $(NAME)

$(BIN_PATH)%.o: $(SRC_SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $(<))...
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(SRC_HEADER_PATH)

$(NAME): $(OBJECTS)
	@echo " "
	@ar rcs $(NAME) $?

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

clean:
	@echo $(RED)[Removing Objects...]$(COLOR_LIMITER)
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)
	@rm -f $(NAME) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re

# Just for test (delete later)
run_b: all
	@echo $(GREEN) -------------------------------------------- $(COLOR_LIMITER)
	@echo $(GREEN)"| ----------- Runing Bonus Tests ----------- |"$(COLOR_LIMITER)
	@echo $(GREEN) -------------------------------------------- $(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -g3 tests_bonus.c $(NAME) -I $(SRC_HEADER_PATH) && ./a.out

remove: fclean
	@echo $(RED)[Removing a.out...]$(COLOR_LIMITER)
	@rm -f a.out