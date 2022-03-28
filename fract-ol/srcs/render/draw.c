/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:18:24 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/28 16:08:26 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_color.h"
#include "fractol.h"
#include "libft.h"
#include <math.h>

static void	plot_while_moving_z(t_window *window, t_complex *c, double max_r);
static void	plot_while_moving_c(t_window *window, t_complex *z, double max_r);

void	draw_julia(
		t_window *window, int init_re, int init_im, double max_r)
{
	t_complex	*c;

	c = complex_new(init_re, init_im);
	plot_while_moving_z(window, c, max_r);
}

void	draw_mandelbrot(
		t_window *window, int init_re, int init_im, double max_r)
{
	t_complex	*z;

	z = complex_new(init_re, init_im);
	plot_while_moving_c(window, z, max_r);
}

static void	plot_while_moving_z(t_window *window, t_complex *c, double max_r)
{
	t_complex	*z;
	double		r;
	double		theta;

	r = 0;
	while (r < max_r)
	{
		printf("r:%f, theta:%f\n", r, theta);
		theta = 0;
		while (theta < M_2_PI)
		{
			z = complex_new(r * cos(theta), r * sin(theta));
			if (zn_is_convergent(z, c, 0))
			{
				printf("plot(x, y) = (%d, %d)\n", (int)z->re * 10, (int)z->im * 10);
				my_mlx_pixel_put(window, z->re * 1000, z->im * 1000, GREEN);
			}
			free(z);
			theta += DELTA_THETA;
		}
		r += DELTA_R;
	}
}

static void	plot_while_moving_c(t_window *window, t_complex *z, double max_r)
{
	t_complex	*c;
	double		r;
	double		theta;

	r = 0;
	while (r <= max_r)
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
