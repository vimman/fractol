/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:53:20 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:53:23 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	burn_init(t_fractal *f)
{
	f->type = BURN;
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

void	ft_burn(t_fractal *f)
{
	double	zi2;
	double	zr2;
	double	zir2;

	f->cr = f->p.x * (f->x2 - f->x1) / WIDTH + f->x1;
	f->ci = f->p.y * (f->y2 - f->y1) / HEIGHT + f->y1;
	f->zr = 0;
	f->zi = 0;
	f->i = -1;
	while (1)
	{
		zi2 = f->zi * f->zi;
		zr2 = f->zr * f->zr;
		zir2 = f->zr * f->zi;
		f->tmp = f->zi;
		f->zi = fabs((double)(zir2 + zir2 + f->ci));
		f->zr = fabs((double)(zr2 - f->tmp * f->tmp + f->cr));
		if (!(zr2 + zi2 < 4 && ++f->i < f->it_max))
			break ;
	}
}
