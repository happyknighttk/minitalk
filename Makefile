SRCS			= utils.o

SRCS_M_CLIENT	= client.o
SRCS_B_CLIENT	= client_bonus.o

SRCS_M_SERVER	= server.o
SRCS_B_SERVER	= server_bonus.o

NAME_CLIENT		= client
NAME_SERVER		= server
CFLAGS			= -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME): all

$(NAME_CLIENT): $(SRCS) $(SRCS_M_CLIENT)
	cc $(CFLAGS) $(SRCS) $(SRCS_M_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRCS) $(SRCS_M_SERVER)
	cc $(CFLAGS) $(SRCS) $(SRCS_M_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT)_bonus: $(SRCS) $(SRCS_B_CLIENT)
	cc $(CFLAGS) $(SRCS) $(SRCS_B_CLIENT) -o $(NAME_CLIENT)_bonus

$(NAME_SERVER)_bonus: $(SRCS) $(SRCS_B_SERVER)
	cc $(CFLAGS) $(SRCS) $(SRCS_B_SERVER) -o $(NAME_SERVER)_bonus

bonus: $(NAME_CLIENT)_bonus $(NAME_SERVER)_bonus

.c.o:
	cc $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(SRCS) $(SRCS_B_SERVER) $(SRCS_M_SERVER) $(SRCS_M_CLIENT) $(SRCS_B_CLIENT)

fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT)_bonus $(NAME_SERVER)_bonus

.PHONY: clean fclean all re bonus
