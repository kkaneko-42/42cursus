/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_det.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:15:48 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/15 03:14:14 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

static t_matrix	*make_submat(t_matrix *src, size_t rm_row, size_t rm_col);
static int		cal_sgn(size_t exp);
static int		validate_param(t_matrix *mat);
static void		cal_submat(
					t_matrix *res, t_matrix *src, size_t rm_row, size_t rm_col);

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
		submat = make_submat(mat, i, 0);
		res += mat->values[i][0] * cal_sgn(i + 2) * mat_det(submat);
		mat_free(submat);
		++i;
	}
	return (res);
}

static t_matrix	*make_submat(t_matrix *src, size_t rm_row, size_t rm_col)
{
	t_matrix	*res;

	res = mat_new(src->row - 1, src->col - 1);
	cal_submat(res, src, rm_row, rm_col);
	return (res);
}

static void	cal_submat(
				t_matrix *res, t_matrix *src, size_t rm_row, size_t rm_col)
{
	size_t		src_i;
	size_t		src_j;
	size_t		dst_i;
	size_t		dst_j;

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
}

static int	cal_sgn(size_t exp)
{
	if (exp % 2 == 0)
		return (1);
	else
		return (-1);
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
