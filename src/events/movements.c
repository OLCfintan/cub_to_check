#include "../../include/cub3d.h"

void	move_forward_backward(t_player *player, char **map, int keycode)
{
	t_vec2	new_pos;
	t_vec2	check;
	float	player_cos;
	float	player_sin;
	int i;

	i = 1 - 2 * (keycode == XK_s);
	player_cos = cos(player->angle) * 0.1 * i;
	player_sin = sin(player->angle) * 0.1 * i;
	new_pos.x = player->x + player_cos;
	new_pos.y = player->y + player_sin;
	check.x = floor(new_pos.x + player_cos * player->radius);
	check.y = floor(new_pos.y + player_sin * player->radius);
	if (map[(int)check.y][(int)player->x] == '0')
		player->y = new_pos.y;
	if (map[(int)player->y][(int)check.x] == '0')
		player->x = new_pos.x;
}

void	move_right_left(t_player *player, char **map, int keycode)
{
	t_vec2	new_pos;
	t_vec2	check;
	float	player_cos;
	float	player_sin;
	float	angle;
	int i;

	i = 1 - 2 * (keycode == XK_d);
	angle = normalize_angle(player->angle + (M_PI_2 * i));
	player_cos = cos(angle) * 0.1;
	player_sin = sin(angle) * 0.1;
	new_pos.x = player->x - player_cos;
	new_pos.y = player->y - player_sin;
	check.x = floor(new_pos.x - player_cos * player->radius);
	check.y = floor(new_pos.y - player_sin * player->radius);
	if (map[(int)check.y][(int)player->x] == '0')
		player->y = new_pos.y;
	if (map[(int)player->y][(int)check.x] == '0')
		player->x = new_pos.x;
}
