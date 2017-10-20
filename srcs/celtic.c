/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:34:55 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/20 23:35:01 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	celtic_init(t_fractal *f)
{
	f->type = CELTIC;
	f->text = 0;
	f->it_zoom = 0;
	f->x1 = -3.36;
	f->x2 = 3.36;
	f->y1 = -2.1;
	f->y2 = 2.1;
	f->it_max = 32;
	f->color = 7;
	f->c.phas1 = 4;
	f->c.phas2 = 6;
	f->c.phas3 = 8;
}

void	ft_celtic(t_fractal *f)
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
		f->tmp = fabs(zi2 - zr2) + f->ci;
		f->zr = 2 * f->zr * f->zi + f->cr;
		f->zi = f->tmp;
		if (!(zi2 + zr2 < 4 && ++f->i < f->it_max))
			break ;
	}
}
