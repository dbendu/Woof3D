/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Woof3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:28:08 by user              #+#    #+#             */
/*   Updated: 2020/05/10 12:19:09 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF3D_h
# define WOOF3D_h

# include "data.h"
# include "WoofDefines.h"

t_data	woof_init();
void	woof_quit(t_data *data);

void	playerUpdate(t_data *data, t_hero *hero);
void	draw(t_data *data);

t_ray	*raycast(float pov, t_map *map);
SDL_Color	setColor(int r, int g, int b, int a);
SDL_Rect	setRect(int x, int y, int w, int h);
t_point_xy	xyInit(int x, int y);

void	mouseCapture(t_data *data, SDL_MouseMotionEvent mouse);
char	*ft_strjoin(char const *s1, char const *s2);
t_menu		menuInit(t_data data);
void		drawMenu(t_data *data);
void			key_pressed(t_data *data, SDL_Keycode button);
void			key_release(t_data *data, SDL_Keycode button);
t_button	initButton(t_data data, int x, int y);
SDL_Rect	setButton(t_button button, int x, int y);
void		buttonDraw(t_data *data, t_button *button, SDL_Color col, int press);
t_buttonInit	buttonInitData(SDL_Rect rect, t_point_xy shift, bool map);
t_button	*startButtonsInit(t_data data, int size, t_buttonInit init, ...);
void		renderMaps(t_data *data);
void		renderButtons(t_data *data, t_button *button, int buttonPress);
t_font	fontInit(t_data data, int font_size, const char *message, SDL_Color color);
void		fontDraw(t_data data, t_font font, int x, int y);
t_mouse		mouseInit(t_data data, const char *path, int w, int h);
void	drawMouse(t_data data, t_mouse mouse);
t_wnd		wnd_init(const char *title, int width, int height);
t_map		map_init(const char *filename);
t_keyboard	keyboard_init(void);
t_minimap	minimap_init(t_data data);
t_map	get_input(const char *filename);
t_options		initOptions(t_data data);
void	drawOptions(t_data *data);

#endif
