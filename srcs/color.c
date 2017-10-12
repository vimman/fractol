/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:53:32 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:53:35 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mov_phaze(int keycode, t_env *e)
{
	if (keycode == KEY_COMMA)
	{
		e->f.c.phas1 += 0.1;
		e->f.c.phas2 += 0.2;
		e->f.c.phas3 += 0.3;
	}
	else
	{
		e->f.c.phas1 -= 0.1;
		e->f.c.phas2 -= 0.2;
		e->f.c.phas3 -= 0.3;
	}
	redraw(e);
}

int		rgb2int(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

int		sinwave(t_col *c, double i)
{
	int	r;
	int	g;
	int	b;

	r = sin(c->freq1 * i + c->phas1) * c->width + c->center;
	g = sin(c->freq2 * i + c->phas2) * c->width + c->center;
	b = sin(c->freq3 * i + c->phas3) * c->width + c->center;
	return (rgb2int(r, g, b));
}

void	color_point(t_fractal *f)
{
	if (f->color == 1 || f->color == 2 || f->color == 3)
		color_1(f);
	else if (f->color == 4 || f->color == 5 || f->color == 6)
		color_2(f);
	else if (f->color == 7)
		color_7(f);
	else if (f->color == 8)
		color_8(f);
	else if (f->color == 9)
		color_9(f);
}

void	change_color(t_env *e)
{
	if (e->f.color < 9)
		e->f.color++;
	else
		e->f.color = 1;
	redraw(e);
}
