NAME	= fractol
CFLAGS	:= -Wunreachable-code -Ofast -g3 -Wextra -Wall -Werror
LIBMLX	:= ./.lib/MLX42
BIN		:= bin

FILES	= choose_fractal.c color.c funcs_aux.c julia.c \
			keys_hook.c main.c mandelbrot.c mouse_hook.c \
			burning_ship.c tricorn.c

M_PATH	= src

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= $(addprefix  $(M_PATH)/, $(FILES))
OBJS	= $(patsubst %, $(BIN)/%, $(notdir $(SRCS:.c=.o)))

all: $(LIBS) $(BIN) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)


$(LIBS):
ifeq ($(wildcard $(LIBMLX)/build/ ), )
	@cd ./.lib/MLX42/ && cmake -B build
	@cd ./.lib/MLX42/ && cmake --build build -j4
endif

$(BIN):
	@mkdir -p $(BIN)

$(BIN)/%.o: $(M_PATH)/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf $(BIN)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
