/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:09:05 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/14 16:14:31 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLOR_H
# define MLX_COLOR_H
# define RED 0x00ff0000
# define BLUE 0x000000ff
# define GREEN 0x00008000
# define YELLOW 0x00ffff00
# define BLACK 0x0
# define WHITE 0x00ffffff

typedef struct s_trgb
{
	double	t;
	double	r;
	double	g;
	double	b;
}		t_trgb;

int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

#endif
