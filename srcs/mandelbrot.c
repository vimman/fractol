#include "fractol.h"

void	mandel_init(t_fractal *m)
{
	m->type = MANDEL;
	m->x1 = -2.1;
	m->x2 = 2.1;
	m->y1 = -2.1;
	m->y2 = 2.1;
	m->zoom = 2.57;
	m->it_max = 42;
	m->img_x = HEIGHT + m->zoom;
	m->img_y = HEIGHT + m->zoom;
	m->zoom_x = m->zoom * m->img_x / (m->x2 - m->x1);
	m->zoom_y = m->zoom * m->img_y / (m->y2 - m->y1);
	m->color = 2;
	init_point(&m->p);
}

void	ft_mandelbrot(t_fractal *m)
{
	m->cr = m->p.x / m->zoom_x + m->x1;
	m->ci = m->p.y / m->zoom_y + m->y1;
	m->zr = 0;
	m->zi = 0;
	m->i = -1;
	while (m->zr * m->zr + m->zi * m->zi < 4 && ++m->i < m->it_max)
	{
		m->tmp = m->zr;
		m->zr = m->zr * m->zr - m->zi * m->zi + m->cr;
		m->zi = 2 * m->zi * m->tmp + m->ci;
	}
}
