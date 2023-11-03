NAME = fdf
SRCS = fdf.c get_next_line.c pixels.c utils.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
INCLUDES = -I$(LIBFT_DIR) $(MLX_INC)
CFLAGS =  -Wall -Wextra -g
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm 

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
