NAME	:= inception

$(NAME):
	cd srcs && docker-compose up -d

all: $(NAME)

fclean:
	docker-compose down

re: fclean all

.PHONY: $(NAME) all fclean re
