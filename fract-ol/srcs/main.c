/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:52:03 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/30 01:09:57 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

static void	validate_args(int ac, char **av);
static int	str_is_all_num(const char *str);
static void	exit_with_usage(void);

int	main(int ac, char **av)
{
	t_window	*window;

	validate_args(ac, av);
	window = init_window(WIN_W, WIN_H, WIN_TITLE);
	if (ft_strncmp(av[1], JULIA, ft_strlen(av[1]) + 1) == 0)
		draw_julia(window, ft_atoi(av[2]), ft_atoi(av[3]));
	else if (ft_strncmp(av[1], MANDELBROT, ft_strlen(av[1]) + 1) == 0)
		draw_mandelbrot(window, ft_atoi(av[2]), ft_atoi(av[3]));
	else
		exit_with_usage();
	//set_hooks(window);
	mlx_put_image_to_window(window->mlx,
							window->mlx_win,
							window->img,
							WIN_W / 2,
							WIN_H / 2);
	mlx_loop(window->mlx);
	return (0);
}

static void	validate_args(int ac, char **av)
{
	if (ac != 4)
		exit_with_usage();
	if (!str_is_all_num(av[2]) || !str_is_all_num(av[3]))
		exit_with_usage();
}

static int	str_is_all_num(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0x00)
	{
		if (!ft_isdigit(str[i]) && (i != 0 || str[i] != '-'))
			return (0);
		++i;
	}
	return (1);
}

static void	exit_with_usage(void)
{
	ft_printf(USAGE);
	exit(1);
}
