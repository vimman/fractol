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

void	text(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "iterations");
	mlx_string_put(e->mlx, e->win, 150, 10, 0xFFFFFF, ft_itoa(e->f.it_max));
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "color");
	mlx_string_put(e->mlx, e->win, 150, 30, 0xFFFFFF, ft_itoa(e->f.color));
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF,
			"change color           : c");
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF,
			"change hue             : <>");
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF,
			"change iteration       : []");
	mlx_string_put(e->mlx, e->win, 10, 110, 0xFFFFFF,
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
