/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:47:05 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/28 13:25:36 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include "libft.h"

t_complex	*complex_add(t_complex *z, t_complex *w)
{
	return (complex_new(z->re + w->re, z->im + w->im));
}
