NAME	:=	miniRT
SRCS	:=	main.c
VPATH	:= 	srcs:\
			srcs/render
OBJ_DIR	:= ./objs
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS	:= $(OBJS:.o=.d)
INC_DIR := ./includes $(LIBFT_DIR) $(LIBMAT_DIR)

LIBFT		:= libft.a
LIBFT_DIR	:= ./libft
MLX			:= libmlx.a
MLX_DIR		:= ./minilibx-linux
WITH_MLX	:= $(MLX_DIR)/$(MLX) -L $(MLX_DIR) -lmlx -I $(MLX_DIR) -lXext -lX11 -lm
LIBMAT		:= libmat.a
LIBMAT_DIR	:= ./libmat

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -MMD -MP #-fsanitize=leak -g

$(NAME): $(OBJ_DIR) $(OBJS)
	make bonus -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	make affine debug -C $(LIBMAT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(LIBMAT_DIR)/$(LIBMAT) $(WITH_MLX) -o $@ -I $(INC_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR):
	mkdir -p $@

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR) 
	make clean -C $(MLX_DIR)
	make clean -C $(LIBMAT_DIR)
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)
	rm -f $(MLX_DIR)/$(MLX)
	rm -f $(LIBMAT_DIR)/$(LIBMAT)

re:			fclean all

-include $(DEPS)

.PHONY:     all clean fclean re
