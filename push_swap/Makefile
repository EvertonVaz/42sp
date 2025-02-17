NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Werror -Wextra -g3 -Ofast -flto

# Paths for libraries
LIB_PATH = ./libs/libft
LIB_NAME = libft.a

# Colors Definition
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths for libraries
BIN_PATH = ./bin/
MANDATORY_SOURCES_PATH = ./src/
BONUS_SOURCES_PATH = ./src/bonus/
INCLUDES_PATH = ./includes/

MANDATORY_SOURCES = \
	main.c stack_init.c stack_utils.c moves_swap.c moves_push.c \
	moves_rotate.c moves_reverse_rotate.c push_swap.c find_infos.c \
	cost_moves.c calculate_cost.c arguments.c

BONUS_SOURCES = \
	checker_bonus.c

OBJECTS = $(addprefix $(BIN_PATH), $(MANDATORY_SOURCES:%.c=%.o))

OBJECTS_BONUS = $(addprefix $(BIN_PATH), $(BONUS_SOURCES:%.c=%.o))

all: libft $(BIN_PATH) $(NAME)

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@make -C $(LIB_PATH) --no-print-directory
endif

$(BIN_PATH)%.o: $(MANDATORY_SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling push_swap]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" --------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| PUSH_SWAP executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIB_PATH) -lft
	@echo " "

$(BIN_PATH)%.o: $(BONUS_SOURCES_PATH)%.c
	@echo $(GREEN)[Compiling checker]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES_PATH)
	@echo " "

bonus: $(BONUS_NAME) $(NAME) $(OBJECTS) libft

$(BONUS_NAME): $(OBJECTS_BONUS)
	@echo $(CYAN)" --------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| CHECKER executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJECTS_BONUS) -L $(OBJECTS) -L $(LIB_PATH) -lft
	@echo " "


$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

tests:
	$(CC) $(CFLAGS) /.tests/test.c && ./a.out

test3:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-3 -n 3))
		./push_swap $(ARG) | ./checker $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test5:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-5 -n 5))
		./push_swap $(ARG) | ./checker $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test10:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-9 -n 10))
		./push_swap $(ARG) | ./checker $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test100:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 500))
		./push_swap $(ARG) | ./checker $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l


clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@rm -rf $(LIB_PATH)/$(LIB_NAME)
	@rm -rf $(BIN_PATH)

fclean: clean fclean_bonus
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(NAME)

fclean_bonus:
ifneq ($(wildcard $(BONUS_NAME)),)
	@echo $(RED)[Removing $(BONUS_NAME) executable]$(COLOR_LIMITER)
	@rm -rf $(BONUS_NAME)
endif

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re libft bonus