
#include "utils.h"

void	draw_verical_line(t_image *image, t_vec2 start, t_vec2 end, int color)
{
	if (start.x != end.x || start.y >= SCREEN_HEIGHT)
		return ;
	if (start.y < 0)
		start.y = 0;
	if (end.y >= SCREEN_HEIGHT)
		end.y = SCREEN_HEIGHT - 1;
	while (start.y <= end.y)
	{
		plot_pixel(image, start.x, start.y, color);
		start.y++;
	}
}
