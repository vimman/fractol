#include "fractol.h"

void	newton_init(t_fractal *m)
{
	m->x1 = -1;
	m->x2 = 1;
	m->y1 = -1;
	m->y2 = 1;
	m->zoom = 0.1;
	m->it_max = 17;
	m->img_x = WIDTH;
	m->img_y = HEIGHT;
	m->color = 3;
	m->type = NEWTON;
	init_point(&m->p);
}

void	ft_newton(t_fractal *m)
{
	m->zr = (m->p.x - WIDTH / 2) / (m->zoom * WIDTH);
	m->zi = (m->p.y - HEIGHT / 2) / (m->zoom * HEIGHT);
	m->i = 0;
	m->tmp = 1.0;
	while (m->tmp > 0.000001 && ++m->i < m->it_max)
	{
		m->cr = m->zr;
		m->ci = m->zi;

		m->tmp = (m->zr * m->zr + m->zi * m->zi)
			* (m->zr * m->zr + m->zi * m->zi);
		m->zr = (2 * m->zr * m->tmp + m->zr * m->zr
				- m->zi * m->zi) / (3.0 * m->tmp);
		m->zi = (2 * m->zi * (m->tmp - m->cr)) / (3.0 * m->tmp);
		m->tmp = (m->zr - m->cr) * (m->zr - m->cr) *
			(m->zi - m->ci) / (m->zi - m->ci);
	}
}
