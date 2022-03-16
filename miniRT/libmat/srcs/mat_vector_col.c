/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_vector_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:16:13 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/14 23:17:31 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_matrix	*mat_vector_col(double x, double y, double z)
{
	t_matrix	*res;

	res = mat_new(4, 1);
	res->values[0][0] = x;
	res->values[1][0] = y;
	res->values[2][0] = z;
	res->values[3][0] = 1;
	return (res);
}
