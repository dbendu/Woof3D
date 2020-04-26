 #include <stdio.h>
#include "Woof3D.h"
#include "Woof_defines.h"

static void	usage(void)
{
	write(2, "usage: ./a.out [map]\n", 21);
}

static void	print_map(t_map *map)
{
	for (size_t row = 0; row < vec_size(&map->map); ++row) {
		for (size_t col = 0; col < vec_size(&map->map[row]); ++col) {
			// printf("%zu - %zu\n", col * CELL_SIZE, row * CELL_SIZE);
			if (map->hero.position.y > (int)row * CELL_SIZE && map->hero.position.y < (int)(row + 1) * CELL_SIZE &&
				map->hero.position.x > (int)col * CELL_SIZE && map->hero.position.x < (int)(col + 1) * CELL_SIZE)
				printf("X");
			else
				printf("%c", map->map[row][col].wall ? '#' : ' ');
		}
		printf("\n");
	}
}

int main(int argc, const char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map = get_input(argv[1]);
		print_map(&map);
		run(map);
		woof_quit(&map);
	}
	else
		usage();
	return (0);
}
