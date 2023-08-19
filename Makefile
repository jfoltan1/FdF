NAME = fdf
<<<<<<< HEAD
SRCS = fdf.c gnl/get_next_line.c gnl/get_next_line_utils.c pixels.c utils.c
=======
SRCS = fdf.c gnl/get_next_line.c gnl/get_next_line_utils.c
>>>>>>> 078e68eb377fe1b4142a93e27cd82e51f01182b6
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
INCLUDES = -I$(LIBFT_DIR) $(MLX_INC)
<<<<<<< HEAD
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm 
=======
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
>>>>>>> 078e68eb377fe1b4142a93e27cd82e51f01182b6

$(NAME): $(SRCS) $(LIBFT) $(MLX_LIB)
	cc $(CFLAGS) $(INCLUDES) $(SRCS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
