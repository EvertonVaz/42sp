# _*_ Makefile _*_

NAME_MC 	= client
NAME_MS 	= server
NAME_BC 	= client_bonus
NAME_BS		= server_bonus

CC			= cc
CFLAGS		= -Werror -Wall -Wextra -g3
PRINTF		= ./libs/ft_printf/libftprintf.a

M_INC		= -I src/minitalk.h
B_INC		= -I bonus_src/minitalk_bonus.h

PATH_M		=	src/
CLIENT_M	=	$(addprefix $(PATH_M), client.c)
SERVER_M	=	$(addprefix $(PATH_M), server.c)

PATH_B		=	$(PATH_M)/bonus/
CLIENT_B	=	$(addprefix $(PATH_B), client_bonus.c)
SERVER_B	=	$(addprefix $(PATH_B), server_bonus.c)

CLIENT_M_O	=	$(CLIENT_M:%.c=%.o)
SERVER_M_O	=	$(SERVER_M:%.c=%.o)

CLIENT_B_O	=	$(CLIENT_B:%.c=%.o)
SERVER_B_O	= 	$(SERVER_B:%.c=%.o)

BLUE 		= \033[1;36m
WHITE 		= \033[0;39m

all: ft_printf $(NAME_MC) $(NAME_MS)

ft_printf:
	@if ! [ $(T_LIB) ]; then echo "$(BLUE)-*- Creating ft_printf library. -*-$(WHITE)";fi
	@make -C libs/ft_printf/ --no-print-directory

$(NAME_MC): $(CLIENT_M_O)
	$(CC) $(CFLAGS) $< -I $(PATH_M) $(PRINTF) -o $@

$(NAME_MS): $(SERVER_M_O)
	$(CC) $(CFLAGS) $< -I $(PATH_M) $(PRINTF) -o $@

bonus: ft_printf $(NAME_BC) $(NAME_BS)

$(NAME_BC): $(CLIENT_B_O)
	$(CC) $(CFLAGS) $< -I $(PATH_B) $(PRINTF) -o $@

$(NAME_BS): $(SERVER_B_O)
	$(CC) $(CFLAGS) $< -I $(PATH_B) $(PRINTF) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_M_O) $(SERVER_M_O) $(CLIENT_B_O) $(SERVER_B_O)

fclean: clean
	rm -f $(PRINTF)
	rm -f $(NAME_MC) $(NAME_MS) $(NAME_BC) $(NAME_BS)

re: fclean all

.PHONY: all clean fclean re libft