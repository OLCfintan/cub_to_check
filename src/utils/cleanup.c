#include "../../include/cub3d.h"

void	ft_free_matrix(char **mat)
{
	size_t	i;

	i = 0;
	while (mat && mat[i])
		free(mat[i++]);
	free(mat);
}

void	cleanup(t_game *game)
{
	mlx_destroy_image(game->renderer.mlx, game->renderer.image.img);
	mlx_destroy_image(game->renderer.mlx, game->west_texture.image.img);
	mlx_destroy_image(game->renderer.mlx, game->south_texture.image.img);
	mlx_destroy_image(game->renderer.mlx, game->east_texture.image.img);
	mlx_destroy_image(game->renderer.mlx, game->north_texture.image.img);
	mlx_destroy_window(game->renderer.mlx, game->renderer.win);
	mlx_destroy_display(game->renderer.mlx);
	free(game->renderer.mlx);
	ft_free_matrix(game->map);
}
