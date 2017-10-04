#include "fractol.h"

void	color_1(t_fractal *m)
{
	if (m->i == m->it_max)
		m->p.color = YELLOW * m->zr * m->zi * m->cr * m->ci;
	else
		m->p.color = m->i * 255 / m->it_max * 4;
}

void	color_2(t_fractal *m)
{
	if (m->i == m->it_max)
		m->p.color = WHITE * m->zr * m->zi;
	else
		m->p.color = m->i * 16581375 / m->it_max * 5;
}

void	color_3(t_fractal *m)
{
	if (m->i == m->it_max)
		m->p.color = WHITE;
	else
		m->p.color = m->i * 255 / m->it_max;
}

void	color_4(t_fractal *m)
{
	if (m->i == m->it_max)
		m->p.color = m->zi / m->zr;
	else
		m->p.color = m->i * (255 * 255 * 255) / (m->cr / m->ci + m->zr / m->zi);
}

void	color_5(t_fractal *m)
{
	if (m->i == m->it_max)
		m->p.color = m->zi / m->zr;
	else
		m->p.color = m->i * BLUE;
}

void	color_point(t_fractal *m)
{
	if (m->color == 1)
		color_1(m);
	else if (m->color == 2)
		color_2(m);
	else if (m->color == 3)
		color_3(m);
	else if (m->color == 4)
		color_4(m);
	else if (m->color == 5)
		color_5(m);
}

void	change_color(t_env *e)
{
	if (e->m.color < 5)
		e->m.color++;
	else
		e->m.color = 1;
	redraw(e);
}
