
#include "hooks.h"
#include "utils.h"

void	turn_right(t_player *player)
{
	player->angle += player->turn_speed;
	player->angle = normalize_angle(player->angle);
}

void	turn_left(t_player *player)
{
	player->angle -= player->turn_speed;
	player->angle = normalize_angle(player->angle);
}

int	keypress_hook(int keycode, t_game *game)
{
	game->renderer.re_render = true;
	if (keycode == XK_Escape)
		mlx_loop_end(game->renderer.mlx);
	else if (keycode == XK_Right)
		turn_right(&game->player);
	else if (keycode == XK_Left)
		turn_left(&game->player);
	else if (keycode == XK_w)
		move_forward(&game->player, game->map);
	else if (keycode == XK_s)
		move_backward(&game->player, game->map);
	else if (keycode == XK_a)
		move_left(&game->player, game->map);
	else if (keycode == XK_d)
		move_right(&game->player, game->map);
	return (0);
}
