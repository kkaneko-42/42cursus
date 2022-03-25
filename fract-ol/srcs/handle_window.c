#include "mlx.h"
#include "mlx_window.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_window	*init_window(int width, int height, char *title)
{
	t_window	*res;

	res = (t_window *)ft_calloc(1, sizeof(t_window));
	res->mlx = mlx_init();
	res->mlx_win = mlx_new_window(res->mlx, width, height, title);
	res->img = mlx_new_image(res->mlx, width, height);
	res->addr = mlx_get_data_addr(
					res->img,
					&(res->bits_per_pixel),
					&(res->line_length),
					&(res->endian));
	return (res);
}

void	window_close_hook(t_window *window, int (*exit)(void), void *param)
{
	mlx_hook(window->mlx_win,
			EV_CROSS_BUTTON,
			(1L << EV_CROSS_BUTTON),
			(*exit),
			param);
}

void	my_mlx_pixel_put(t_window *window, int x, int y, int color)
{
	char	*dst;

	dst = window->addr +
			(y * window->line_length +
			x * (window->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
