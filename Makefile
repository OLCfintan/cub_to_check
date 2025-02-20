NAME            =   cub3d

CC              =   cc
CFLAGS          =   -Werror -Iinclude -Ilibft -MMD -MP -g3 -fsanitize=address
LDFLAGS         =   -lmlx -lX11 -lXext -lm -Llibft -lft

BUILD_DIR       =   build
SRC_DIR         =   src

SRC             =   $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ             =   $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP             =   $(OBJ:.o=.d)

RM              =   rm -rf

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C libft all
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

-include $(DEP)

clean:
	make -C libft clean
	$(RM) $(BUILD_DIR)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
