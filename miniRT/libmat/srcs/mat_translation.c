/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:50:09 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/14 22:54:53 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_matrix	*mat_translation(double x, double y, double z)
{
	t_matrix	*res;

	res = mat_identity(4, 4);
	res->values[0][3] = x;
	res->values[1][3] = y;
	res->values[2][3] = z;
	return (res);
}
