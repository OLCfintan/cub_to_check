
#pragma once

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>

#define WINDOW_TITLE "Cub3D"
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 720

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

t_renderer	init_renderer(void);
