/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:54:14 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:54:15 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cross(t_env *e)
{
	int	x;
	int	y;
	int size;

	size = 5;
	x = WIDTH / 2 - size;
	y = HEIGHT / 2 - size;
	while (++x <= WIDTH / 2 + size)
		mlx_pixel_put(e->mlx, e->win, x, HEIGHT / 2, WHITE);
	while (++y <= HEIGHT / 2 + size)
		mlx_pixel_put(e->mlx, e->win, WIDTH / 2, y, WHITE);
}

void	text(t_env *e)
{
	cross(e);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "iterations");
	mlx_string_put(e->mlx, e->win, 170, 10, 0xFFFFFF, ft_itoa(e->f.it_max));
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "color");
	mlx_string_put(e->mlx, e->win, 170, 30, 0xFFFFFF, ft_itoa(e->f.color));
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF,
			"change color    : c");
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF,
			"change hue      : <>");
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF,
			"change iteration: []");
	mlx_string_put(e->mlx, e->win, 10, 110, 0xFFFFFF,
			"mouse movement  : space");
	mlx_string_put(e->mlx, e->win, 10, 130, 0xFFFFFF,
			"iterating zoom  : z");
	mlx_string_put(e->mlx, e->win, 10, 150, 0xFFFFFF,
			"reset fractal   : backspace");
	mlx_string_put(e->mlx, e->win, 10, 170, 0xFFFFFF,
			"quit            : q");
}

void	tg_text(t_env *e)
{
	if (e->f.text)
		e->f.text = 0;
	else
		e->f.text = 1;
	redraw(e);
}
