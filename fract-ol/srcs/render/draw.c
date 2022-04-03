/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:18:24 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/30 01:24:43 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_color.h"
#include "fractol.h"
#include "libft.h"
#include <math.h>

static void	plot_while_moving_z(t_window *window, t_complex *c);
static void	plot_while_moving_c(t_window *window, t_complex *z);

void	draw_julia(
		t_window *window, int init_re, int init_im)
{
	t_complex	*c;

	c = complex_new(init_re, init_im);
	plot_while_moving_z(window, c);
}

void	draw_mandelbrot(
		t_window *window, int init_re, int init_im)
{
	t_complex	*z;

	z = complex_new(init_re, init_im);
	plot_while_moving_c(window, z);
}

static void	plot_while_moving_z(t_window *window, t_complex *c)
{
	t_complex	*z_init;
	double		r;
	double		theta;
	int			plot_x;
	int			plot_y;

	r = 0;
	while (r <= 2)
	{
		theta = 0;
		while (theta < 2 * M_PI)
		{
			z_init = complex_new(r * cos(theta), r * sin(theta));
			if (zn_is_convergent(z_init, c, 0))
			{
				plot_x = (int)(z_init->re * 300);
				plot_y = (int)(z_init->im * 300);
				if ((plot_x >= 0 && plot_x < WIN_W) && (plot_y >= 0 && plot_y < WIN_H))
				my_mlx_pixel_put(window, plot_x, plot_y, GREEN);
			}
			free(z_init);
			theta += DELTA_THETA;
		}
		r += DELTA_R;
	}
}

static void	plot_while_moving_c(t_window *window, t_complex *z)
{
	t_complex	*c;
	double		r;
	double		theta;

	r = 0;
	while (r <= 2)
	{
		theta = 0;
		while (theta < M_2_PI)
		{
			c = complex_new(r * cos(theta), r * sin(theta));
			if (zn_is_convergent(z, c, 0))
			{
				printf("in!!r:%f, theta:%f\n", r, theta);
				my_mlx_pixel_put(window, z->re, z->im, GREEN);
				printf("out!!\n");
			}
			free(c);
			theta += DELTA_THETA;
		}
		r += DELTA_R;
	}
}
