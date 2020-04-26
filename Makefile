NAME =				a.out

SRCS =				main.c							\
					woof_quit.c						\
					input/get_input.c				\
					input/init_hero.c				\
					input/read_file.c				\
					input/convert_file_to_map.c		\
					input/find_hero_position.c		\
					raycasting_main.c

SRCS_DIR =			srcs
OBJS_DIR =			objs

OBJS =				$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

INCLUDES_DIRS 		=	includes/
INCLUDES_INPUT		=	$(INCLUDES_DIRS)input/
INCLUDES_LIBFT		=	libft/includes/

INCLUDES =			-I $(INCLUDES_DIRS) -I $(INCLUDES_INPUT) -I $(INCLUDES_LIBFT)

HEADER_LIST			=	hero.h map.h point.h window.h Woof_defines.h Woof3D.h
HEADER_INPUT_LIST	=	input_utils.h input.h

HEADERS				=	$(addprefix $(INCLUDES_DIRS), $(HEADER_LIST))
HEADERS				+=	$(addprefix $(INCLUDES_INPUT), $(HEADER_INPUT_LIST))

FLAGS_COMPILE =		-Wall -Wextra -g

FLAGS_LINK =		-L libft -lft -lSDL2 -lm


all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/input

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	gcc $(FLAGS_COMPILE) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS_DIR) $(OBJS)
	make -C libft
	gcc $(OBJS) $(FLAGS_LINK) -o $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJS_DIR)

c: clean

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

f: clean

re: fclean all

.PHONY: all clean fclean re c f
