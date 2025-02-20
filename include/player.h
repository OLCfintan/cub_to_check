
#pragma once

#include "vec2.h"

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	fov;
	float	half_fov;
	float	radius;
	float	turn_speed;
	float	movement_speed;
}	t_player;

t_player	init_player(char **map);
