NAME =				a.out

SRCS =				main.c								\
					player_update.c						\
					raycasting.c						\
					utils.c								\
					controls/keyboard.c					\
					draw.c								\
					initialization/keyboard_init.c		\
					initialization/map_init.c			\
					initialization/minimap_init.c		\
					initialization/wnd_init.c			\
					initialization/woof_init.c			\
					initialization/input/convert_file_to_map.c	\
					initialization/input/find_hero_position.c	\
					initialization/input/get_input.c			\
					initialization/input/init_hero.c		\
					initialization/input/read_file.c	\
					quit/map_quit.c						\
					quit/minimap_quit.c					\
					quit/wnd_quit.c						\
					quit/woof_quit.c


SRCS_DIR =			srcs
OBJS_DIR =			objs

OBJS =				$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

#-------------------------------------------------------------------------------
#									INCLUDES
#-------------------------------------------------------------------------------

INCLUDES_LIBFT		=	libft/includes/
INCLUDES_DIR =		includes/
INCLUDES_CON_DIR =	$(INCLUDES_DIR)controls/
INCLUDES_GR_DIR =	$(INCLUDES_DIR)graphic/
INCLUDES_STR_DIR =	$(INCLUDES_DIR)structs/
INCLUDES_INIT_DIR =	$(INCLUDES_DIR)initialization/
INCLUDES_INP_DIR =	$(INCLUDES_DIR)initialization/input/
INCLUDES_QUIT_DIR =	$(INCLUDES_DIR)quit/


INCLUDES =			-I $(INCLUDES_DIR) -I $(INCLUDES_CON_DIR)
INCLUDES +=			-I $(INCLUDES_LIBFT) -I $(INCLUDES_GR_DIR)
INCLUDES +=			-I $(INCLUDES_INP_DIR) -I $(INCLUDES_STR_DIR)
INCLUDES +=			-I $(INCLUDES_INIT_DIR) -I $(INCLUDES_QUIT_DIR)

#-------------------------------------------------------------------------------
#									HEADERS
#-------------------------------------------------------------------------------

HEADERS_LIST =		WoofDefines.h			\
					Woof3D.h				\
					wolf_utils.h

HEADERS_CON_LIST =	controls_utils.h		\
					keyboard.h				\
					mouse.h

HEADERS_GR_LIST =	interface.h				\
					minimap.h				\
					wnd.h

HEADERS_INP_LIST =	input_utils.h			\
					input.h

HEADERS_STR_LIST =	data.h					\
					hero.h					\
					map.h					\
					point.h

HEADERS =			$(addprefix $(INCLUDES_DIR), $(HEADERS_LIST))
HEADERS +=			$(addprefix $(INCLUDES_CON_DIR), $(HEADERS_CON_LIST))
HEADERS +=			$(addprefix $(INCLUDES_GR_DIR), $(HEADERS_GR_LIST))
HEADERS +=			$(addprefix $(INCLUDES_INP_DIR), $(HEADERS_INP_LIST))
HEADERS +=			$(addprefix $(INCLUDES_STR_DIR), $(HEADERS_STR_LIST))


#-------------------------------------------------------------------------------
#									FLAGS
#-------------------------------------------------------------------------------

FLAGS_COMPILE =		-Wall -Wextra -Werror -g

FLAGS_LINK =		-L libft -lft -lSDL2 -lm


all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/initialization/input
	mkdir -p $(OBJS_DIR)/controls
	mkdir -p $(OBJS_DIR)/initialization
	mkdir -p $(OBJS_DIR)/quit

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c #$(HEADERS)
	gcc $(FLAGS_COMPILE) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS_DIR) $(OBJS)
	gcc $(OBJS) $(FLAGS_LINK) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

c: clean

fclean: clean
	rm -f $(NAME)

f: clean

re: fclean all

.PHONY: all clean fclean re c f
