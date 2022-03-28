/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:41:54 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/28 13:57:38 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

double	complex_abs(t_complex *z)
{
	return (sqrt(ft_pow(z->re, 2) + ft_pow(z->im, 2)));
}
