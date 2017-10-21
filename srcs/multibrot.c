/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:35:42 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/20 23:35:44 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	multi_init(t_fractal *f)
{
	f->type = MULTI;
	f->multi = 6;
	f->text = 0;
	f->it_zoom = 0;
	f->x1 = -3.36;
	f->x2 = 3.36;
	f->y1 = -2.1;
	f->y2 = 2.1;
	f->it_max = 15;
	f->color = 7;
	f->c.phas1 = 6;
	f->c.phas2 = 10;
	f->c.phas3 = 14;
}

void	ft_multibrot(t_fractal *f)
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
		f->tmp = pow((zr2 + zi2), (f->multi / 2)) *
			cos(f->multi * atan2(f->zi, f->zr)) + f->cr;
		f->zi = pow((zr2 + zi2), (f->multi / 2)) *
			sin(f->multi * atan2(f->zi, f->zr)) + f->ci;
		f->zr = f->tmp;
		if (!(zr2 + zi2 < 4 && ++f->i < f->it_max))
			break ;
	}
}
