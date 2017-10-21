/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:54:08 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:54:09 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	newton_init(t_fractal *f)
{
	f->type = NEWTON;
	f->text = 0;
	f->stop = 0;
	f->it_zoom = 0;
	f->x1 = -2;
	f->x2 = 2;
	f->y1 = -2;
	f->y2 = 2;
	f->it_max = 45;
	f->color = 7;
	f->n1 = 3;
	f->n2 = 3;
	f->c.phas1 = 6;
	f->c.phas2 = 11;
	f->c.phas3 = 16;
}

void	ft_newton(t_fractal *f)
{
	f->zr = f->p.x * (f->x2 - f->x1) / WIDTH + f->x1;
	f->zi = f->p.y * (f->y2 - f->y1) / HEIGHT + f->y1;
	f->i = 0;
	f->tmp = 1.0;
	while (f->tmp > 0.000001 && ++f->i < f->it_max)
	{
		f->cr = f->zr;
		f->ci = f->zi;
		f->tmp = (f->zr * f->zr + f->zi * f->zi)
			* (f->zr * f->zr + f->zi * f->zi);
		f->zr = (2 * f->zr * f->tmp + f->zr * f->zr
				- f->zi * f->zi) / (f->n1 * f->tmp);
		f->zi = (2 * f->zi * (f->tmp - f->cr)) / (f->n2 * f->tmp);
		f->tmp = (f->zr - f->cr) * (f->zr - f->cr) *
			(f->zi - f->ci) / (f->zi - f->ci);
	}
}
