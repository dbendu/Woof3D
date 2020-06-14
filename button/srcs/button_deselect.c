#include "private_button.h"
#include "button.h"

inline
void	button_deselect(t_button button)
{
	button->selected = false;
}
