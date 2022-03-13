NAME	:=	miniRT
CC		:=	gcc
CFLAGS	:=	-MMD -MP #-fsanitize=leak -g
WITH_MLX :=	-lreadline
INC_DIR := ./includes
OBJ_DIR	:= ./objs
VPATH	:=
SRCS	:=
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS	:= $(OBJS:.o=.d)
LIBFT_DIR := ./libft
LIBFT := libft.a

$(NAME): 
	make bonus -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $@ -I $(INC_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

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
