
#include "../../include/cub3d.h"

static t_texture	*get_texture(t_game *g, t_ray *data)
{
	if (data->side == 0)
	{
		if (data->dir.x > 0)
			return (&g->west_texture);
		else
			return (&g->east_texture);
	}
	else
	{
		if (data->dir.y > 0)
			return (&g->north_texture);
		else
			return (&g->south_texture);
	}
}

void	draw_ceiling(t_renderer *renderer, int x, float wall_height)
{
	int	start;
	int	end;
	int	half_height;

	half_height = SCREEN_HEIGHT / 2;
	start = 0;
	end = half_height - wall_height;
	draw_verical_line(&renderer->image,
		(t_vec2){x, start},
		(t_vec2){x, end},
		ft_rgb(0, 0, 0));
}

int	get_texture_y_cord(t_texture *t, int y, int start, float wall_height)
{
	float	normalized_y;

	normalized_y = (y - start) / (2.0f * wall_height);
	return (fmodf((normalized_y * t->height), t->height));
}

void	draw_wall(t_game *g, int x, float wall_height, t_ray *data)
{
	int			y;
	int			start;
	int			end;
	t_texture	*t;
	t_vec2		t_cord;

	t = get_texture(g, data);
	t_cord.x = fmodf(data->hit.x + data->hit.y, 1.0f) * t->width;
	start = g->win_height_2 - wall_height;
	end = (int)(start + 2.0f * wall_height);
	end = end * (end < g->win_height) + (g->win_height - 1) * (end >= g->win_height);
	y = start;
	y *= !(y < 0);
	while (y < end)
	{
		t_cord.y = get_texture_y_cord(t, y, start, wall_height);
		plot_pixel(&g->renderer.image, x, y,
			get_pixel_color(&t->image, t_cord.x, t_cord.y));
		y++;
	}
}

void	draw_floor(t_renderer *renderer, int x, float wall_height)
{
	int		start;
	int		end;
	int		half_height;

	half_height = SCREEN_HEIGHT / 2;
	start = half_height + wall_height;
	end = SCREEN_HEIGHT - 1;
	draw_verical_line(&renderer->image,
		(t_vec2){x, start},
		(t_vec2){x, end},
		ft_rgb(100, 100, 100));
}
