/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:54:03 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:54:05 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			drag(int button, int x, int y, t_env *e)
{
	(void)button;
	if (x > 0 && y > 0)
	{
		e->f.basex = x;
		e->f.basey = y;
		e->f.dndrop = 1;
	}
	return (0);
}

int			drop(int button, int x, int y, t_env *e)
{
	(void)button;
	(void)x;
	(void)y;
	e->f.dndrop = 0;
	return (0);
}

void		move(int keycode, t_env *e)
{
	if (keycode == KEY_LEFT)
	{
		e->f.x1 -= 0.01 * (e->f.x2 - e->f.x1);
		e->f.x2 -= 0.01 * (e->f.x2 - e->f.x1);
	}
	else if (keycode == KEY_RIGHT)
	{
		e->f.x1 += 0.01 * (e->f.x2 - e->f.x1);
		e->f.x2 += 0.01 * (e->f.x2 - e->f.x1);
	}
	else if (keycode == KEY_DOWN)
	{
		e->f.y1 += 0.01 * (e->f.y2 - e->f.y1);
		e->f.y2 += 0.01 * (e->f.y2 - e->f.y1);
	}
	else if (keycode == KEY_UP)
	{
		e->f.y1 -= 0.01 * (e->f.y2 - e->f.y1);
		e->f.y2 -= 0.01 * (e->f.y2 - e->f.y1);
	}
	redraw(e);
}

int			mmove(int x, int y, t_env *e)
{
	if (e->f.stop)
	{
		if (e->f.type == JULIA || e->f.type == JULIUX)
		{
			e->f.cr = 0.004 * (-x + WIDTH / 2);
			e->f.ci = 0.002 * (-y + HEIGHT / 2);
		}
		else if (e->f.type == NEWTON)
		{
			e->f.n1 = (x * 6.0 / WIDTH);
			e->f.n2 = (y * 6.0 / HEIGHT);
		}
		else if (e->f.type == MULTI)
			e->f.multi -= 0.001 * (-x + WIDTH / 2);
	}
	else if (e->f.dndrop)
	{
		e->f.x1 -= 0.00005 * ((x - e->f.basex) * (e->f.x2 - e->f.x1));
		e->f.x2 -= 0.00005 * ((x - e->f.basex) * (e->f.x2 - e->f.x1));
		e->f.y1 -= 0.00005 * ((y - e->f.basey) * (e->f.y2 - e->f.y1));
		e->f.y2 -= 0.00005 * ((y - e->f.basey) * (e->f.y2 - e->f.y1));
	}
	redraw(e);
	return (0);
}
