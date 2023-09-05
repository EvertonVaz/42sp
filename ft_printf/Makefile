NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

# Path Definition
BIN_PATH = ./bin/
MANDATORY_HEADER_PATH = ./mandatory/ft_printf.h
MANDATORY_SOURCES_PATH = ./mandatory/
BONUS_HEADER_PATH = ./bonus/ft_printf.h
BONUS_SOURCES_PATH = ./bonus/

# Colors Definition
GREEN = "\033[32m"
RED = "\033[31m"
VIOLATE = "\033[38;5;208m"
COLOR_LIMITER = "\033[0m"

# Sources Definition
SOURCES = \
		ft_printf.c \
		ft_printf_utils.c \
		ft_put_pointer.c \
		ft_putnbr_base.c \

BONUS_SOURCES = \
		ft_printf_bonus.c \
		ft_lens_bonus.c \
		ft_puts_bonus.c \
		ft_strings_bonus.c \
		ft_width_bonus.c \

# Objects Definition
OBJECTS = $(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))
BONUS_OBJECTS = $(addprefix $(BIN_PATH), $(BONUS_SOURCES:%.c=%.o))

# Verification of Mandatory Files
PRINTF_MANDATORY = ft_printf.o
MANDATORY_CHECK = $(shell ar -t libftprintf.a ft_printf.o 2>&1)

# Verification of Bonus Files
PRINTF_BONUS = ft_printf_bonus.o
BONUS_CHECK = $(shell ar -t $(NAME) $(PRINTF_BONUS) 2>&1)

ifneq ($(BONUS_CHECK), $(PRINTF_BONUS))
all: $(BIN_PATH) $(NAME)
endif


$(BIN_PATH)%.o: $(MANDATORY_SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $(<))...
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(MANDATORY_HEADER_PATH)

$(NAME): $(OBJECTS)
	@echo $(VIOLATE) -------------------------------------------- $(COLOR_LIMITER)
	@echo $(VIOLATE)"| libftprintf.a Was Generated Successfully!! |"$(COLOR_LIMITER)
	@echo $(VIOLATE) -------------------------------------------- $(COLOR_LIMITER)
	@echo " "
	@ar rcs $(NAME) $?

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

ifeq ($(MANDATORY_CHECK), $(PRINTF_MANDATORY))
bonus: fclean
	@make --no-print-directory \
	OBJECTS="$(BONUS_OBJECTS)" \
	MANDATORY_HEADER_PATH="$(BONUS_HEADER_PATH)" \
	MANDATORY_SOURCES_PATH="$(BONUS_SOURCES_PATH)"
else
bonus:
	@make --no-print-directory \
	OBJECTS="$(BONUS_OBJECTS)" \
	MANDATORY_HEADER_PATH="$(BONUS_HEADER_PATH)" \
	MANDATORY_SOURCES_PATH="$(BONUS_SOURCES_PATH)"
endif

clean:
	@echo $(RED)[Removing Objects...]$(COLOR_LIMITER)
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)
	@rm -f $(NAME) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# Just for test (delete later)
run_m: all
	@echo $(GREEN) -------------------------------------------- $(COLOR_LIMITER)
	@echo $(GREEN)"| --------- Runing Mandatory Tests --------- |"$(COLOR_LIMITER)
	@echo $(GREEN) -------------------------------------------- $(COLOR_LIMITER)
	@$(CC) $(CFLAGS) tests_mandatory.c $(NAME) -I $(MANDATORY_HEADER_PATH) && ./a.out

run_b: remove bonus
	@echo $(GREEN) -------------------------------------------- $(COLOR_LIMITER)
	@echo $(GREEN)"| ----------- Runing Bonus Tests ----------- |"$(COLOR_LIMITER)
	@echo $(GREEN) -------------------------------------------- $(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -g3 tests_bonus.c $(NAME) -I $(BONUS_HEADER_PATH) && ./a.out

remove: fclean
	@echo $(RED)[Removing a.out...]$(COLOR_LIMITER)
	@rm -f a.out