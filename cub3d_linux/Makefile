NAME = cub3d

SRC =	main.c\
		pre_map_check_a.c\
		pre_map_check_b.c\
		pre_map_check_c.c\
		pre_map_check_d.c\
		pre_map_check_e.c\
		map_check_a.c\
		map_check_b.c\
		map_check_c.c\
		map_check_d.c\
		map_check_e.c\
		render_next_frame_a.c\
		render_next_frame_b.c\
		key_pressed_a.c\
		key_pressed_b.c\
		structs_init.c\
		utils_a.c\
		utils_b.c\
		wall_collision_a.c\
		wall_collision_b.c\

SRC_MAP = srcs/

SRCS = $(addprefix $(SRC_MAP), $(SRC))

FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -lm -Lmlx -lXext -lX11 -lm -lz

CC = clang

LIBS = libft/libft.a libmlx.a

HDRS = -I mlx -I libft/hdrs -I includes/

OBJS := $(SRCS:.c=.o)

OPT_FLAGS = -O2

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C  libft/ all
	@$(MAKE) -C mlx/ all
	@mv mlx/libmlx.a ./libmlx.a
	@$(CC) -o $@ $^ $(LIBS) $(HDRS) $(MLX_FLAGS) $(FLAGS)
	@echo "\033[1m\033[32mSuccessfully Compiled\033[39m"

%.o: %.c
	@$(CC) -o $@ -c $<  $(HDRS) $(FLAGS)

clean: 
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C mlx/ clean
	@rm $(OBJS)
	@echo "\033[1m\033[33mCleaning Object Files\033[39m"

fclean: 
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C mlx/ clean
	@rm -f $(OBJS)
	@rm -f libmlx.a
	@rm -f $(NAME)
	@echo "\033[1m\033[31mPurged Objects and Executables\033[39m"

re: fclean all

.PHONY: all clean fclean re cub3d