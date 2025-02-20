
#include "renderer.h"
#include "utils.h"

static int	render_next_frame(t_game *g)
{
	float	distance;
	int		wall_height;
	int		x;
	float	ray_angle;
	t_ray	data;

	if (!g->renderer.re_render)
		return (1);
	ray_angle = g->player.angle - g->player.half_fov;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		distance = raycasting(ray_angle, g, &data);
		distance *= cos(ray_angle - g->player.angle);
		wall_height = floor(g->win_height_2 / distance);
		draw_ceiling(&g->renderer, x, wall_height);
		draw_wall(g, x, wall_height, &data);
		draw_floor(&g->renderer, x, wall_height);
		ray_angle += g->ray_step;
		x++;
	}
	mlx_put_image_to_window(g->renderer.mlx, g->renderer.win,
		g->renderer.image.img, 0, 0);
	g->renderer.re_render = false;
	return (0);
}

void	render(t_game *game)
{
	mlx_loop_hook(game->renderer.mlx, render_next_frame, game);
	mlx_loop(game->renderer.mlx);
	cleanup(game);
}
