/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:54:27 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:54:28 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tg_it_zoom(t_env *e)
{
	if (e->f.it_zoom)
		e->f.it_zoom = 0;
	else
		e->f.it_zoom = 1;
}

void	key_zoom(int keycode, t_env *e)
{
	int	x;
	int	y;

	x = WIDTH / 2;
	y = HEIGHT / 2;
	if (keycode == KEY_EQUAL)
		zoom(e, x, y, 1.1);
	else
		zoom(e, x, y, 0.9);
	redraw(e);
}

void	zoom(t_env *e, int x, int y, double ratio)
{
	double	x_curs;
	double	y_curs;

	x_curs = (x * (e->f.x2 - e->f.x1)) / WIDTH + e->f.x1;
	y_curs = (y * (e->f.y2 - e->f.y1)) / HEIGHT + e->f.y1;
	e->f.x1 = x_curs - (((x_curs - e->f.x1) / ratio));
	e->f.y1 = y_curs - (((y_curs - e->f.y1) / ratio));
	e->f.x2 = x_curs - (((x_curs - e->f.x2) / ratio));
	e->f.y2 = y_curs - (((y_curs - e->f.y2) / ratio));
	if (e->f.it_zoom)
	{
		if (ratio < 1)
			e->f.it_max--;
		else
			e->f.it_max++;
	}
}
