#include "../../include/cub3d.h"

void	turn_right_left(t_player *player, int keycode)
{
	keycode = 1 - 2 * (keycode == XK_Left);
	player->angle += (player->turn_speed * keycode);
	player->angle = normalize_angle(player->angle);
}

int	keypress_hook(int keycode, t_game *game)
{
	game->renderer.re_render = true;
	if (keycode == XK_Escape)
		mlx_loop_end(game->renderer.mlx);
	else if (keycode == XK_Right || keycode == XK_Left)
		turn_right_left(&game->player, keycode);
	else if (keycode == XK_w || keycode == XK_s)
		move_forward_backward(&game->player, game->map, keycode);
	else if (keycode == XK_a || keycode == XK_d)
		move_right_left(&game->player, game->map, keycode);
	return (0);
}