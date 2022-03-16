/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_vector_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:17:57 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/14 23:18:32 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_matrix	*mat_vector_row(double x, double y, double z)
{
	t_matrix	*res;

	res = mat_new(1, 4);
	res->values[0][0] = x;
	res->values[0][1] = y;
	res->values[0][2] = z;
	res->values[0][3] = 1;
	return (res);
}
