#ifndef WOOF3D_ACTIONS_H
#define WOOF3D_ACTIONS_H

#include <stdbool.h>

typedef struct		s_actions
{
	bool			move_forward;
	bool			move_back;
	bool			move_left;
	bool			move_right;

	bool			run;
	bool			sonic_mode;

	bool			to_pause;
	bool			to_main;
	bool			exit;
	bool			to_game;
}					t_actions;

#endif
