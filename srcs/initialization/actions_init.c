#include "initialization/initialization.h"
#include "ft_memory.h"

t_actions	actions_init(void)
{
	t_actions actions;

	ft_memset(&actions, 0, sizeof(t_actions));
	return (actions);
}