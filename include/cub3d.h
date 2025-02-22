#pragma once

#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../libft/libft.h"
#include "colors.h"

#define TWO_PI 6.283185307179586232


#define WINDOW_TITLE "Cub3D"
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 720

#define CUB3D_USAGE "usage ./cub3d [/path/to/map.cub]!"
#define ERR_INVALID_FILENAME "The map file must be ending with .cub!"
#define ERR_NO_PLAYER "No player found!"

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

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

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


typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_texture
{
	t_image	image;
	int		width;
	int		height;
}	t_texture;

typedef struct s_renderer
{
	void		*mlx;
	void		*win;
	t_image		image;
	bool		re_render;
}	t_renderer;


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


char	**parse_map(const char *file_name);
void	setup(t_game *game, int ac, char **av);
void	render(t_game *game);
float	raycasting(float angle, t_game *game, t_ray *data_ptr);

int		keypress_hook(int keycode, t_game *g);
void	move_forward_backward(t_player *player, char **map, int keycode);
void	move_right_left(t_player *player, char **map, int keycode);

void	ft_panic(const char *msg);
int		ft_error(const char *msg);
int		ft_rgb(int r, int g, int b);
float	deg_to_rad(float deg);
float	normalize_angle(float angle);
void	cleanup(t_game *g);
void	ft_free_matrix(char **mat);
void	plot_pixel(t_image *img, int x, int y, int color);
int		get_pixel_color(t_image *img, int x, int y);
void	draw_verical_line(t_image *image, t_vec2 start, t_vec2 end, int color);
void	load_texture(t_game *g, t_texture *t, char *file_name);
void	draw_ceiling(t_renderer *renderer, int x, float wall_height);
void	draw_wall(t_game *g, int x, float wall_height, t_ray *data);
void	draw_floor(t_renderer *renderer, int x, float wall_height);


t_vec2	vec2_rotate(t_vec2 v, float angle);
t_vec2	vec2_normalize(t_vec2 v);
t_vec2	new_vec2(float x, float y);

t_player	init_player(char **map);

t_renderer	init_renderer(void);