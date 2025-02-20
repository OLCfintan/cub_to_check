
#include "cub3d.h"
#include <math.h>
#include "utils.h"

void	init_ray_data(t_ray *ray)
{
	ray->map_x = (int)ray->pos.x;
	ray->map_y = (int)ray->pos.y;
	ray->delta.x = fabs(1 / ray->dir.x);
	ray->delta.y = fabs(1 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map_x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - ray->pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map_y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - ray->pos.y) * ray->delta.y;
	}
}

float	get_distance(t_ray *ray)
{
	float	distance;

	if (ray->side == 0)
	{
		distance = (ray->map_x - ray->pos.x + (1 - ray->step.x) / 2)
			/ ray->dir.x;
		ray->hit.x = ray->map_x;
		ray->hit.y = ray->pos.y + distance * ray->dir.y;
	}
	else
	{
		distance = (ray->map_y - ray->pos.y + (1 - ray->step.y) / 2)
			/ ray->dir.y;
		ray->hit.x = ray->pos.x + distance * ray->dir.x;
		ray->hit.y = ray->map_y;
	}
	return (distance);
}

float	raycasting(float angle, t_game *game, t_ray *ray_ptr)
{
	t_ray	ray;
	float	distance;

	ray.pos = (t_vec2){game->player.x, game->player.y};
	ray.dir = (t_vec2){cos(angle), sin(angle)};
	init_ray_data(&ray);
	while (game->map[ray.map_y][ray.map_x] == '0')
	{
		if (ray.side_dist.x < ray.side_dist.y)
		{
			ray.side_dist.x += ray.delta.x;
			ray.map_x += ray.step.x;
			ray.side = 0;
		}
		else
		{
			ray.side_dist.y += ray.delta.y;
			ray.map_y += ray.step.y;
			ray.side = 1;
		}
	}
	distance = get_distance(&ray);
	*ray_ptr = ray;
	return (distance);
}
