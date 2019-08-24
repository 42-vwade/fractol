
####	Main Configuration File	################
NAME		=	fractol
BUILD		=	build
LIBFT		=	libft
MLX			=	.minilibx
LIBFT		:=	$(LIBFT)/libft.a
MLX			:=	$(MLX)/libmlx.a
FLAGS		=	-Wall -Werror -Wextra

SOURCE		=	$(shell find ./source ! -name "._*" -regex ".*\\.[c]")

####	Auto Setting	################
OBJECTS		=	$(SOURCE:.c:=.o)

####	################
####	System Control	################

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	gcc -o $@ $(FLAGS) $^

$(OBJECTS): $(SOURCE)
	gcc -c $(FLAGS) $^

$(LIBFT):
	make -C $(@D)

$(MLX):
	make -C $(@D)

####	Required	################
clean:
	make clean -C $(dir $(LIBFT)) $(dir $(MLX))
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C $(dir $(LIBFT)) $(dir $(MLX))

re: fclean all

.PHONY: re fclean clean all
