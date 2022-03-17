/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:58:03 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/17 22:45:03 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	t_matrix	*mat;
	double	**values;

	if (ac != 16)
		return (1);
	mat = new_mat(4, 4);
	values = mat->values;
	put_values(values, av);
	mat_print(mat_inv(mat));
	return (0);
}

static void	put_values(double **values, char **av)
{
	size_t	i;
	size_t	j;
	size_t	cnt_av;

	cnt_av = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			values[i][j] = strtod(av[cnt_av], NULL);
			++cnt_av;
			++j;
		}
		++i;
	}
}
