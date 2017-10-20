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

	size = 4;
	x = WIDTH / 2 - size;
	y = HEIGHT / 2 - size;
	while (x <= WIDTH / 2 + size)
		put_pixel(x++, HEIGHT / 2, RED, e);
	while (y <= HEIGHT / 2 + size)
		put_pixel(y++, WIDTH / 2, RED, e);
}

void	text(t_env *e)
{
	cross(e); //TODO
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "iterations");
	mlx_string_put(e->mlx, e->win, 150, 10, 0xFFFFFF, ft_itoa(e->f.it_max));
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "hue");
	mlx_string_put(e->mlx, e->win, 150, 30, 0xFFFFFF, ft_itoa(e->f.c.phas1));
	mlx_string_put(e->mlx, e->win, 170, 30, 0xFFFFFF, ft_itoa(e->f.c.phas2));
	mlx_string_put(e->mlx, e->win, 190, 30, 0xFFFFFF, ft_itoa(e->f.c.phas3));
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF,
			"change color           : c");
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF,
			"change hue             : <>");
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF,
			"change iteration       : []");
	mlx_string_put(e->mlx, e->win, 10, 110, 0xFFFFFF,
			"mouse changes variable : space");
	mlx_string_put(e->mlx, e->win, 10, 130, 0xFFFFFF, "phas2");
	mlx_string_put(e->mlx, e->win, 10, 150, 0xFFFFFF, "phas3");
	mlx_string_put(e->mlx, e->win, 10, 170, 0xFFFFFF,
			"mouse changes variable : space");
	mlx_string_put(e->mlx, e->win, 10, 190, 0xFFFFFF,
			"mouse changes variable : space");
}

void	tg_text(t_env *e)
{
	if (e->f.text)
		e->f.text = 0;
	else
		e->f.text = 1;
	redraw(e);
}
