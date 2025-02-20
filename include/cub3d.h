
#pragma once

#include "renderer.h"
#include "vec2.h"
#include "player.h"
#include <X11/X.h>
#include "libft.h"
#include "colors.h"

#define TWO_PI 6.283185307179586232

#define CUB3D_USAGE "usage ./cub3d [/path/to/map.cub]!"
#define ERR_INVALID_FILENAME "The map file must be ending with .cub!"
#define ERR_NO_PLAYER "No player found!"

typedef struct s_game
{
	t_renderer	renderer;
	t_player	player;
	t_texture	west_texture;
	t_texture	east_texture;
	t_texture	north_texture;
	t_texture	south_texture;
	char		**map;
	int			win_height;
	int			win_height_2;
	float		ray_step;
}	t_game;

typedef struct s_ray
{
	t_vec2	dir;
	int		map_x;
	int		map_y;
	t_vec2	pos;
	t_vec2	step;
	int		side;
	t_vec2	delta;
	t_vec2	side_dist;
	t_vec2	hit;
}	t_ray;

char	**parse_map(const char *file_name);
void	setup(t_game *game, int ac, char **av);
void	render(t_game *game);
float	raycasting(float angle, t_game *game, t_ray *data_ptr);
