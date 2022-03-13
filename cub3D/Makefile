NAME	:=	cub3D
CC		:=	gcc
CFLAGS	:=	-MMD -MP #-fsanitize=leak -g

INC_DIR := ./includes
OBJ_DIR	:= ./objs
VPATH	:= srcs
SRCS	:=	
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS	:= $(OBJS:.o=.d)
LIBFT_DIR := ./libft
LIBFT	:= libft.a
MLX		:= libmlx.a
MLX_DIR	:= ./minilibx-linux
WITH_MLX := $(MLX_DIR)/$(MLX) -L $(MLX_DIR) -lmlx -I $(MLX_DIR) -lXext -lX11 -lm

$(NAME): $(OBJ_DIR) $(OBJS)
	make bonus -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $@ -I $(INC_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

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
