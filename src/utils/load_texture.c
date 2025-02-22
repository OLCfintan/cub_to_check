#include "../../include/cub3d.h"

void	load_texture(t_game *g, t_texture *t, char *file_name)
{
	t->image.img = mlx_xpm_file_to_image(g->renderer.mlx,
			file_name, &t->width, &t->height);
	if (!t->image.img)
		ft_panic("could not load texture!");
	t->image.addr = mlx_get_data_addr(t->image.img,
			&t->image.bits_per_pixel, &t->image.size_line,
			&t->image.endian);
	if (!t->image.img)
		ft_panic("could not get texture data addr!");
}
