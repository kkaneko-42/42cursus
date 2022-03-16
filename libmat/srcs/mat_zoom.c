/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:55:05 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/14 22:56:11 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_matrix	*mat_zoom(double x, double y, double z)
{
	t_matrix	*res;

	res = mat_identity(4, 4);
	res->values[0][0] = x;
	res->values[1][1] = y;
	res->values[2][2] = z;
	return (res);
}
