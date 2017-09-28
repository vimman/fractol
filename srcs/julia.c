#include "fractol.h"

void	julia_init(t_fractal *m)
{
	m->type = JULIA;
	m->x1 = -3.2;
	m->x2 = 2;
	m->y1 = -2;
	m->y2 = 1.2;
	//m->cr = 0.285;
	//m->ci = 0.01;
	m->cr = 0.002 * m->movx;
	m->ci = 0.001 * m->movy;
	m->zoom = 200;
	m->it_max = 26;
	m->img_x = (m->x2 - m->x1) * m->zoom;
	m->img_y = (m->x2 - m->x1) * m->zoom;
	init_point(&m->p);
}

void	ft_julia(t_fractal *m)
{
	m->zr = m->p.x / m->zoom + m->x1;
	m->zi = m->p.y / m->zoom + m->y1;
	m->i = 0;
	while (m->zr * m->zr + m->zi * m->zi < 4 && ++m->i < m->it_max)
	{
		m->tmp = m->zr;
		m->zr = m->zr * m->zr - m->zi * m->zi + m->cr;
		m->zi = 2 * m->zi * m->tmp + m->ci;
	}
}
