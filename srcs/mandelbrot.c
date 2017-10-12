/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:53:58 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:54:00 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_init(t_fractal *f)
{
	f->type = MANDEL;
	f->text = 0;
	f->it_zoom = 0;
	f->x1 = -3.36;
	f->x2 = 3.36;
	f->y1 = -2.1;
	f->y2 = 2.1;
	f->it_max = 20;
	f->color = 7;
	f->c.phas1 = 4;
	f->c.phas2 = 6;
	f->c.phas3 = 8;
}

void	ft_mandelbrot(t_fractal *f)
{
	double	zi2;
	double	zr2;

	f->cr = f->p.x * (f->x2 - f->x1) / WIDTH + f->x1;
	f->ci = f->p.y * (f->y2 - f->y1) / HEIGHT + f->y1;
	f->zr = 0;
	f->zi = 0;
	f->i = -1;
	while (1)
	{
		zi2 = f->zi * f->zi;
		zr2 = f->zr * f->zr;
		f->tmp = f->zr;
		f->zr = zr2 - zi2 + f->cr;
		f->zi = 2 * f->zi * f->tmp + f->ci;
		if (!(zr2 + zi2 < 4 && ++f->i < f->it_max))
			break ;
	}
}
