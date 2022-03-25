NAME	:=	minishell
CC		:=	gcc
MLX			:= libmlx.a
MLX_DIR		:= ./minilibx-linux
WITH_MLX	:= $(MLX_DIR)/$(MLX) -L $(MLX_DIR) -lmlx -I $(MLX_DIR) -lXext -lX11 -lm
CFLAGS	:=	-Wall -Wextra -Werror -MMD -MP #-fsanitize=address -g
INCLUDE :=	-I ./includes
OBJ_DIR	:= ./objs
VPATH	:=	srcs:
SRCS	:=	main.c
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS	:= $(OBJS:.o=.d)
LIBFT_DIR := ./libft
LIBFT := libft.a


$(NAME): $(OBJ_DIR) $(OBJS)
	make bonus -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(WITH_MLX) -o $@ $(INCLUDE)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< $(WITH_MLX) -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR) 
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)

re:			fclean all

-include $(DEPS)

.PHONY:     all clean fclean re
