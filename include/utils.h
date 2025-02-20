
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cub3d.h"

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
