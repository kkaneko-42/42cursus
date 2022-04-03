/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:52:18 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/30 01:22:26 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define USAGE "Usage: {name of fractol set(julia or mandelbrot)}\n\
	{real part of init nbr}\n	{imaginary part of init nbr}\n"
# define JULIA "julia"
# define MANDELBROT "mandelbrot"
# define WIN_W 1366
# define WIN_H 768
# define WIN_TITLE "Fract-ol"
# define DEFAULT_MAX_R 1000
# define MAX_CAL 50
# define DELTA_R 0.05
# define DELTA_THETA 0.05
# define ZOOM_RATE 0.01
# include "ft_complex.h"
# include "mlx_window.h"
# include "mlx.h"

int		zn_is_convergent(t_complex *z, t_complex *c, size_t cnt_cal);
void	draw_julia(
		t_window *window, int init_re, int init_im);
void	draw_mandelbrot(
		t_window *window, int init_re, int init_im);
void	set_hooks(t_window *window);

#endif
