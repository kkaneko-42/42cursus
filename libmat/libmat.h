/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:28:01 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/14 23:18:40 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAT_H
# define LIBMAT_H
# define MALLOC_ERR "Memory allocation error\n"
# define MAT_ADD_ERR "Matrix add failed\n"
# define MAT_MUL_ERR "Matrix mul failed\n"
# include <stdlib.h>

typedef struct s_matrix
{
	double	**values;
	size_t	row;
	size_t	col;
}			t_matrix;

/* normal */
void		mat_puterror(const char *msg);
void		mat_free(t_matrix *mat);
t_matrix	*mat_new(size_t row, size_t col);
t_matrix	*mat_add(t_matrix *a, t_matrix *b);
t_matrix	*mat_mul_scalar(int k, t_matrix *a);
t_matrix	*mat_mul(t_matrix *a, t_matrix *b);
t_matrix	*mat_identity(size_t row, size_t col);

/* affine */
t_matrix	*mat_rotation_x(double alpha);
t_matrix	*mat_rotation_y(double beta);
t_matrix	*mat_rotation_z(double gamma);
t_matrix	*mat_rotation_any(t_matrix *vec, double theta);
t_matrix	*mat_translation(double x, double y, double z);
t_matrix	*mat_zoom(double x, double y, double z);
t_matrix	*mat_vector_col(double x, double y, double z);
t_matrix	*mat_vector_row(double x, double y, double z);

#endif
