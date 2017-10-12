/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:53:38 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:54:54 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	color_1(t_fractal *f)
{
	if (f->color == 1)
	{
		if (f->i == f->it_max)
			f->p.color = YELLOW * f->zr * f->zi * f->cr * f->ci;
		else
			f->p.color = f->i * 255 / f->it_max * 4;
	}
	else if (f->color == 2)
	{
		if (f->i == f->it_max)
			f->p.color = WHITE * f->zr * f->zi;
		else
			f->p.color = f->i * 16581375 / f->it_max * 5;
	}
	else if (f->color == 3)
	{
		if (f->i == f->it_max)
			f->p.color = WHITE;
		else
			f->p.color = f->i * 255 / f->it_max;
	}
}

void	color_2(t_fractal *f)
{
	if (f->color == 4)
	{
		if (f->i == f->it_max)
			f->p.color = f->zi / f->zr;
		else
			f->p.color = f->i * (255 * 255 * 255)
				/ (f->cr / f->ci + f->zr / f->zi);
	}
	else if (f->color == 5)
	{
		if (f->i == f->it_max)
			f->p.color = f->zi / f->zr;
		else
			f->p.color = f->i * BLUE;
	}
	else if (f->color == 6)
	{
		if (f->i == f->it_max)
			f->p.color = rgb2int(0, 0, 0);
		else
			f->p.color = f->i * rgb2int(255, 150, 0) / (f->zi * f->zr / 10);
	}
}

void	color_7(t_fractal *f)
{
	double	zn;
	double	continuous_index;

	f->c.freq1 = 0.1;
	f->c.freq2 = 0.1;
	f->c.freq3 = 0.1;
	f->c.center = 200;
	f->c.width = 55;
	zn = sqrt(f->zr * f->zr + f->zi * f->zi);
	continuous_index = f->i + 1 + (log(2) / zn) / log(2);
	if (f->i == f->it_max)
		f->p.color = 0;
	else
		f->p.color = sinwave(&f->c, continuous_index);
}

void	color_8(t_fractal *f)
{
	double	zn;
	double	continuous_index;

	f->c.freq1 = 0.7;
	f->c.freq2 = 0.7;
	f->c.freq3 = 0.7;
	f->c.center = 150;
	f->c.width = 100;
	zn = sqrt(f->zr * f->zr - f->zi * f->zi);
	continuous_index = f->i + 1 - (log(2) / zn) / log(2);
	if (f->i == f->it_max)
		f->p.color = 0;
	else
		f->p.color = sinwave(&f->c, continuous_index);
}

void	color_9(t_fractal *f)
{
	double	zn;
	double	continuous_index;

	f->c.freq1 = 2.4;
	f->c.freq2 = 2.4;
	f->c.freq3 = 2.4;
	f->c.center = 200;
	f->c.width = 55;
	zn = sqrt(f->zr * f->zr + f->zi * f->zi);
	continuous_index = f->i + 1 + (log(2) / zn) / log(2);
	if (f->i == f->it_max)
		f->p.color = 0;
	else
		f->p.color = sinwave(&f->c, continuous_index);
}
