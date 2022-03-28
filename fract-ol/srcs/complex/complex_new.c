/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:22:33 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/28 12:23:40 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include "libft.h"

t_complex	*complex_new(double re, double im)
{
	t_complex	*res;

	res = ft_calloc(1, sizeof(t_complex));
	res->re = re;
	res->im = im;
	res->abs = complex_abs(res);
	return (res);
}
