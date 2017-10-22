/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:52:12 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/21 00:52:15 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	bird_init(t_fractal *f)
{
	f->type = BIRD;
	f->text = 0;
	f->it_zoom = 0;
	f->x1 = -3.36;
	f->x2 = 3.36;
	f->y1 = -2.1;
	f->y2 = 2.1;
	f->it_max = 19;
	f->color = 7;
	f->c.phas1 = 5;
	f->c.phas2 = 7;
	f->c.phas3 = 9;
}

void	ft_bird(t_fractal *f)
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
		f->tmp = f->zi;
		f->zi = ((zr2 * 3) - zi2) * fabs(f->zi) + f->ci;
		f->zr = (zr2 - (zi2 * 3)) * fabs(f->zr) + f->cr;
		if (!(zr2 + zi2 < 4 && ++f->i < f->it_max))
			break ;
	}
}
