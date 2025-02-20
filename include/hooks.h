
#pragma once

#include "cub3d.h"
#include <X11/keysym.h>

int		keypress_hook(int keycode, t_game *g);
void	move_forward(t_player *player, char **map);
void	move_backward(t_player *player, char **map);
void	move_left(t_player *player, char **map);
void	move_right(t_player *player, char **map);
