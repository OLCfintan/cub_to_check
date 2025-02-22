#include "../include/cub3d.h"

void	init_ray_data(t_ray *ray)
{
	int cnd;
	ray->map_x = (int)ray->pos.x;
	ray->map_y = (int)ray->pos.y;
	ray->delta.x = fabs(1 / ray->dir.x);
	ray->delta.y = fabs(1 / ray->dir.y);

	cnd = (ray->dir.x >= 0);
	ray->step.x = -(!cnd) + cnd;
	ray->side_dist.x = ((-ray->map_x + ray->pos.x) * (!cnd - cnd) + cnd) * ray->delta.x;
	cnd = (ray->dir.y >= 0);
	ray->step.y = -(!cnd) + cnd;
	ray->side_dist.y = ((-ray->map_y + ray->pos.y) * (!cnd - cnd) + cnd) * ray->delta.y;
}

float	get_distance(t_ray *ray)
{
	int		cnd;
	float	distance;

	cnd = (ray->side == 0);
    distance = ((ray->map_x - ray->pos.x + (1 - ray->step.x) / 2) / ray->dir.x) * cnd 
	        + ((ray->map_y - ray->pos.y + (1 - ray->step.y) / 2) / ray->dir.y) * (!cnd);

	ray->hit.x = ray->map_x * (cnd) + (ray->pos.x + distance * ray->dir.x) * (!cnd);
	ray->hit.y = (ray->pos.y + distance * ray->dir.y) * (cnd) + ray->map_y * (!cnd);

	return (distance);
}

float	raycasting(float angle, t_game *game, t_ray *ray_ptr)
{
	t_ray	ray;
	int 	check;
	float	distance;

	ray.pos = (t_vec2){game->player.x, game->player.y};
	ray.dir = (t_vec2){cos(angle), sin(angle)};
	init_ray_data(&ray);
	while (game->map[ray.map_y][ray.map_x] == '0')
	{
		check = (ray.side_dist.x < ray.side_dist.y);
		ray.side = (ray.side_dist.x >= ray.side_dist.y);
		ray.side_dist.x += ray.delta.x * check;
		ray.map_x += ray.step.x * check;
		ray.side_dist.y += ray.delta.y * (!check);
		ray.map_y += ray.step.y * (!check);
	}
	distance = get_distance(&ray);
	*ray_ptr = ray;
	return (distance);
}
