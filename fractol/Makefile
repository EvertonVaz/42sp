NAME	= fractol
CFLAGS	:= -Wunreachable-code -Ofast -g3 -Wextra -Wall -Werror
LIBMLX	:= lib/MLX42
BIN		:= bin

FILES	= choose_fractal.c color.c funcs_aux.c julia.c keys_hook.c \
			main.c mandelbrot.c mouse_hook.c

BFILES	= choose_fractal_bonus.c color_bonus.c funcs_aux_bonus.c julia_bonus.c \
			keys_hook_bonus.c main_bonus.c mandelbrot_bonus.c mouse_hook_bonus.c \
			burning_ship_bonus.c tricorn_bonus.c

M_PATH	= src/mandatory
B_PATH	= src/bonus
HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= $(addprefix  $(M_PATH)/, $(FILES))
OBJS	= $(patsubst %, $(BIN)/%, $(notdir $(SRCS:.c=.o)))

ifdef WITH_BONUS
	FILES = $(BFILES)
	M_PATH = $(B_PATH)
endif

all: $(LIBS) $(BIN) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)


$(LIBS):
ifeq ($(wildcard $(LIBMLX)/build/ ), )
	@cd lib/MLX42/ && cmake -B build
	@cd lib/MLX42/ && cmake --build build -j4
endif

$(BIN):
	@mkdir -p $(BIN)

$(BIN)/%.o: $(M_PATH)/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@printf "Compiling: $(notdir $<)\n"

bonus:
	@$(MAKE) WITH_BONUS=TRUE --no-print-directory

clean:
	@rm -rf $(BIN)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
