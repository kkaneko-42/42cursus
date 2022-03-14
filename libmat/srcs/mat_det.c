/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_det.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:15:48 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/15 02:42:33 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

static t_matrix	*cal_submat(t_matrix *src, size_t rm_row, size_t rm_col);
static int		int_pow(int a, int b);
static int		validate_param(t_matrix *mat);

//using cofactor expansion(in col 1)
double	mat_det(t_matrix *mat)
{
	size_t		i;
	t_matrix	*submat;
	double		res;

	if (validate_param(mat))
		return (0);
	if (mat->row == 1)
		return (mat->values[0][0]);
	res = 0;
	i = 0;
	while (i < mat->row)
	{
		submat = cal_submat(mat, i, 0);
		res += mat->values[i][0] * int_pow(-1, i + 2) * mat_det(submat);
		mat_free(submat);
		++i;
	}
	return (res);
}

static t_matrix	*cal_submat(t_matrix *src, size_t rm_row, size_t rm_col)
{
	size_t		src_i;
	size_t		src_j;
	size_t		dst_i;
	size_t		dst_j;
	t_matrix	*res;

	res = mat_new(src->row - 1, src->col - 1);
	src_i = 0;
	dst_i = 0;
	while (src_i < src->row)
	{
		src_j = 0;
		dst_j = 0;
		if (src_i != rm_row)
		{
			while (src_j < src->col)
			{
				if (src_j != rm_col)
					res->values[dst_i][dst_j++] = src->values[src_i][src_j];
				++src_j;
			}
			++dst_i;
		}
		++src_i;
	}
	return (res);
}

static int	int_pow(int a, int b)
{
	if (b == 0)
		return (1);
	else if (b == 1)
		return (a);
	else
		return (int_pow(a, b - 1) * int_pow(a, b - 2));
}

static int	validate_param(t_matrix *mat)
{
	if (mat == NULL || mat->values == NULL)
		return (1);
	else if (mat->col != mat->row)
	{
		mat_puterror("mat_det: param is not square matrix\n");
		return (1);
	}
	else
		return (0);
}
/*
//debug
#include <stdio.h>
int main(int ac, char **av)
{
	t_matrix	*mat = mat_new(3, 3);
	double	**values = mat->values;

	values[0][0] = 7;
	values[0][1] = 2;
	values[0][2] = 8;
	values[1][0] = 8;
	values[1][1] = 2;
	values[1][2] = 7;
	values[2][0] = 8;
	values[2][1] = 5;
	values[2][2] = 1;
	printf("res:%lf\n", mat_det(mat));
	return (0);
}
*/
