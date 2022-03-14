/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_inv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:48:53 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/15 02:42:14 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <stdio.h>


static int		validate_param(t_matrix *src);
static t_matrix	*cal_submat(t_matrix *src, size_t rm_row, size_t rm_col);
static t_matrix	*cal_adj_mat(t_matrix *src);
static int		int_pow(int a, int b);

//calculate by definition
t_matrix	*mat_inv(t_matrix *src)
{
	t_matrix	*res;
	t_matrix	*adj;

	if (validate_param(src))
		return (NULL);
	adj = cal_adj_mat(src);
	res = mat_mul_scalar(1 / mat_det(src), adj);
	mat_free(adj);
	return (res);
}

static t_matrix	*cal_adj_mat(t_matrix *src)
{
	size_t		i;
	size_t		j;
	t_matrix	*res;
	t_matrix	*tmp;
	t_matrix	*submat;

	res = mat_new(src->row, src->col);
	i = 0;
	while (i < src->row)
	{
		j = 0;
		while (j < src->col)
		{
			submat = cal_submat(src, i, j);
			res->values[i][j] = int_pow(-1, i + j + 2) * mat_det(submat);
			mat_free(submat);
			++j;
		}
		++i;
	}
	tmp = res;
	res = mat_transpose(res);
	mat_free(tmp);
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

static int	validate_param(t_matrix *src)
{
	if (src == NULL || src->values == NULL)
		return (1);
	else if (mat_det(src) == 0)
	{
		mat_puterror(MAT_NOT_REGULAR);
		return (1);
	}
	return (0);
}
/*
//debug
#include <stdio.h>
int main(void)
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
	mat_print(mat_inv(mat));
	return (0);
}
*/
