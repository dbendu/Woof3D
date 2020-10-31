NAME 		=		wolf3d

SRCS		=		button/button_add_title.c\
					button/button_create.c\
					button/button_deselect.c\
					button/button_destroy.c\
					button/button_draw.c\
					button/button_select.c\
					button/button_uid.c\
					controls/keyboard.c\
					controls/mouse.c\
					initialization/input/convert_file_to_map.c\
					initialization/input/find_hero_position.c\
					initialization/input/get_input.c\
					initialization/input/init_hero.c\
					initialization/input/read_file.c\
					initialization/keyboard_init.c\
					initialization/map_init.c\
					initialization/minimap_init.c\
					initialization/wnd_init.c\
					initialization/woof_init.c\
					menu/main_menu_cycle.c\
					menu/menu_add_button.c\
					menu/menu_check_hover.c\
					menu/menu_create.c\
					menu/menu_destroy.c\
					menu/menu_draw.c\
					menu/menu_select_button.c\
					menu/menu_select_next.c\
					menu/menu_select_prev.c\
					menu/menu_selected_uid.c\
					quit/map_quit.c\
					quit/minimap_quit.c\
					quit/wnd_quit.c\
					quit/woof_quit.c\
					draw_viz.c\
					game_cycle.c\
					main.c\
					map_render.c\
					pause_cycle.c\
					raycasting.c\
					update.c\
					utils.c


SRCS_DIR 	=		srcs
OBJS_DIR	=		objs

OBJS		=		$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

#-------------------------------------------------------------------------------
#									INCLUDES
#-------------------------------------------------------------------------------

INCLUDES_LIBFT		=	./libft/includes/
INCLUDES_DIR =			./includes/
INCLUDES_SDL2		=	./SDL2_lib/include/

INCLUDES =			-I $(INCLUDES_DIR) -I $(INCLUDES_LIBFT) -I $(INCLUDES_SDL2)

#-------------------------------------------------------------------------------
#									HEADERS
#-------------------------------------------------------------------------------

HEADERS_LIST =		woof3d.h\
					woofdefines.h\
					button/button.h\
					button/private_button.h\
					controls/keyboard.h\
					controls/mouse.h\
					graphic/minimap.h\
					graphic/wnd.h\
					initialization/init_all.h\
					initialization/initialization.h\
					initialization/input/input.h\
					initialization/input/input_utils.h\
					menu/private_menu.h\
					menu/sdl_menu.h\
					quit/quit.h\
					quit/quit_all.h\
					structs/data.h\
					structs/hero.h\
					structs/map.h\
					structs/point.h\
					structs/ray.h\

HEADERS =			$(addprefix $(INCLUDES_DIR), $(HEADERS_LIST))

#-------------------------------------------------------------------------------
#									LIBFT
#-------------------------------------------------------------------------------

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_LINK = -L$(LIBFT_DIR) -lft

#-------------------------------------------------------------------------------
#									SDL_2
#-------------------------------------------------------------------------------

SDL2_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
LIBSDL2_DIR = ./SDL2_lib/
LIBSDL2			= $(LIBSDL2_DIR)lib

LINK_SDL2 		= -L$(LIBSDL2) $(SDL2_FLAGS)
#-------------------------------------------------------------------------------
#									FLAGS
#-------------------------------------------------------------------------------

FLAGS_COMPILE =		-Wall -Wextra -Werror -g

FLAGS_LINK =		-lm $(LIBFT_LINK) $(SDL_2_FLAGS) $(LINK_SDL2)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/initialization/input
	mkdir -p $(OBJS_DIR)/controls
	mkdir -p $(OBJS_DIR)/initialization
	mkdir -p $(OBJS_DIR)/quit
	mkdir -p $(OBJS_DIR)/menu/srcs
	mkdir -p $(OBJS_DIR)/button/srcs

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	gcc $(FLAGS_COMPILE) $(INCLUDES) -o $@ -c $<

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	gcc $(OBJS) $(FLAGS_LINK) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

sdl:
	sh ./configure.sh

clean_sdl:
	rm -rf temp_src
	rm -rf build*
	rm -rf SDL2_lib

c: clean

fclean:
	rm -rf $(OBJS_DIR)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

f: clean

re: fclean all

.PHONY: all clean fclean re c f
