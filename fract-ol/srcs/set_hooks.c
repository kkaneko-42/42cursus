/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:37:24 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/28 14:43:18 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_hooks(t_window *window)
{
	mlx_hook(window->mlx_win);
	mlx_key_hook(window->mlx_win);
	mlx_mouse_hook(window->mlx_win);
}
