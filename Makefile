NAME = cub3d
CC = cc
FLAGS          =   -Werror -Wextra -Werror -g3 -fsanitize=address
MLXFLAGS         =   -lmlx -lX11 -lXext -lm -Llibft #-lft
RM = rm -rf
SRCS = $(shell find . -type f -name '*.c')
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(FLAGS) $(MLXFLAGS) -o $(NAME)
	@echo "making is done :)"

$(OBJS): %.o: %.c
	@$(CC) $(FLAGS) -c $< -g $(MLXFLAGS) -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re : fclean
	@make
