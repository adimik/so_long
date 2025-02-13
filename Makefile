NAME = so_long
CC = clang
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -ffast-math -flto
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = main.c map_size.c game.c map_array.c map_data.c map_put_img.c \
		transparency.c movement.c valid_move.c exit_move.c map_check.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

LFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lft -lmlx  -lX11 -lXext -lXrender -lm -flto

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) fclean
	
re: fclean all

debug: clean
	$(MAKE) CFLAGS='-Wall -Wextra -Werror -g' all
