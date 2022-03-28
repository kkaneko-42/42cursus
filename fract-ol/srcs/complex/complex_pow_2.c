/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_pow_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:24:13 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/28 13:58:07 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex	*complex_pow_2(t_complex *z)
{
	double	res_re;
	double	res_im;

	res_re = ft_pow(z->re, 2) - ft_pow(z->im, 2);
	res_im = 2 * z->re * z->im;
	return (complex_new(res_re, res_im));
}
