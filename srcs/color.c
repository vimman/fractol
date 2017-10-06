#include "fractol.h"

int		rgb2int(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

int		sinwave(t_col *c, int i)
{
	int	r;
	int	g;
	int	b;


	r = sin(c->freq1 * i + c->phas1) * c->width + c->center;
	g = sin(c->freq2 * i + c->phas2) * c->width + c->center;
	b = sin(c->freq3 * i + c->phas3) * c->width + c->center;
	return (rgb2int(r, g, b));
}

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

void	color_6(t_fractal *m)
{
	if (m->i == m->it_max)
		m->p.color = rgb2int(0, 0, 0);
	else
		m->p.color = m->i * rgb2int(255, 150, 0) / (m->zi * m->zr / 10);
}

void	color_7(t_fractal *m)
{
	t_col	c;

	c.freq1 = 0.6;
	c.freq2 = 0.6;
	c.freq3 = 0.6;
	c.phas1 = 4;
	c.phas2 = 6;
	c.phas3 = 8;
	c.center = 200;
	c.width = 55;
	if (m->i == m->it_max)
		m->p.color = 0;
	else
		m->p.color = sinwave(&c, m->i);
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
	else if (m->color == 6)
		color_6(m);
	else if (m->color == 7)
		color_7(m);
}

void	change_color(t_env *e)
{
	if (e->m.color < 7)
		e->m.color++;
	else
		e->m.color = 1;
	redraw(e);
}
