/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zn_is_convergent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:14:04 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/28 16:07:11 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int			check_convergent(
					t_complex *z, t_complex *c, size_t cnt_cal);
static t_complex	*get_next_z(t_complex *z, t_complex *c);

int	zn_is_convergent(t_complex *z, t_complex *c, size_t cnt_cal)
{
	t_complex	*z_next;
	int			res;

	//printf("|z|:%f\n", z->abs);
	if (z->abs > 2)
		return (0);
	else if (check_convergent(z, c, cnt_cal))
		return (1);
	else
	{
		z_next = get_next_z(z, c);
		if (zn_is_convergent(z_next, c, cnt_cal + 1))
			res = 1;
		else
			res = 0;
		free(z_next);
		return (res);
	}
}

static int	check_convergent(t_complex *z, t_complex *c, size_t cnt_cal)
{
	t_complex	*z_pow_2;

	if (cnt_cal == MAX_CAL)
		return (1);
	/*
	z_pow_2 = complex_pow_2(z);
	if ((z_pow_2->re - z->re + c->re == 0)
		&& (z_pow_2->im - z->im + c->im == 0))
	{
		return (1);
	}
	*/
	return (0);
}

static t_complex	*get_next_z(t_complex *z, t_complex *c)
{
	t_complex	*z_pow_2;
	t_complex	*z_next;

	z_pow_2 = complex_pow_2(z);
	z_next = complex_add(z_pow_2, c);
	free(z_pow_2);
	return (z_next);
}