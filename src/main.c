
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	setup(&game, ac, av);
	render(&game);
}
