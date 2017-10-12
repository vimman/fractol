/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:53:50 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:53:52 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_fractal *f)
{
	f->type = JULIA;
	f->text = 0;
	f->stop = 0;
	f->it_zoom = 0;
	f->dndrop = 0;
	f->x1 = -3.2;
	f->x2 = 3.2;
	f->y1 = -2;
	f->y2 = 2;
	f->cr = 0.285;
	f->ci = 0.01;
	f->it_max = 26;
	f->color = 6;
	f->c.phas1 = 8;
	f->c.phas2 = 3;
	f->c.phas3 = 5;
}

void	ft_julia(t_fractal *f)
{
	double	zi2;
	double	zr2;

	f->zr = f->p.x * (f->x2 - f->x1) / WIDTH + f->x1;
	f->zi = f->p.y * (f->y2 - f->y1) / HEIGHT + f->y1;
	f->i = 0;
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
