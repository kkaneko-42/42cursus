/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:43:25 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/28 13:58:40 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H
# include <stdlib.h>

typedef struct s_complex
{
	double	re;
	double	im;
	double	abs;
}	t_complex;

double		ft_pow(double a, int b);
t_complex	*complex_new(double re, double im);
double		complex_abs(t_complex *z);
t_complex	*complex_add(t_complex *z, t_complex *w);
t_complex	*complex_pow_2(t_complex *z);

#endif
