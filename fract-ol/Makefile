NAME	:=	fractol
CC		:=	gcc
CFLAGS	:=	-MMD -MP -fsanitize=address -g
OBJ_DIR	:= ./objs
VPATH	:=	srcs:\
			srcs/render:\
			srcs/window:\
			srcs/complex:\
			srcs/utils
SRCS	:=	main.c \
			draw.c \
			zn_is_convergent.c \
			handle_color.c \
			handle_window.c \
			complex_new.c \
			complex_abs.c \
			complex_add.c \
			complex_pow_2.c \
			ft_pow.c
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS	:= $(OBJS:.o=.d)
LIBFT_DIR := ./libft
LIBFT := libft.a
MLX			:= libmlx.a
MLX_DIR		:= ./minilibx-linux
WITH_MLX	:= $(MLX_DIR)/$(MLX) -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDE :=	-I ./includes -I $(LIBFT_DIR) -I $(MLX_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	make bonus -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(WITH_MLX) -o $@ $(INCLUDE)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)
	rm -f $(MLX_DIR)/$(MLX)

re:			fclean all

-include $(DEPS)

.PHONY:     all clean fclean re
