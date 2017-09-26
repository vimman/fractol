#include "fractol.h"

void	mandel_init(t_mandelbrot *m)
{
	m->x1 = -2.1;
	m->x2 = 2.1;
	m->y1 = -2.1;
	m->y2 = 2.1;
	m->zoom = 1;
	m->it_max = 42;
	m->img_x = HEIGHT + m->zoom;
	m->img_y = HEIGHT + m->zoom;
	m->zoom_x = m->img_x / (m->x2 - m->x1);
	m->zoom_y = m->img_y / (m->y2 - m->y1);
	m->color = 2;
	init_point(&m->p);
}

void	color_1(t_mandelbrot *m)
{
	if (m->i == m->it_max)
		m->p.color = YELLOW * m->zr * m->zi * m->cr * m->ci;
	else
		m->p.color = m->i * 65025 / m->it_max * 4;
}

void	color_2(t_mandelbrot *m)
{
	if (m->i == m->it_max)
		m->p.color = WHITE * m->zr * m->zi;
	else
		m->p.color = m->i * 16581375 / m->it_max * 5;
}

void	color_point(t_mandelbrot *m)
{
	if (m->color == 1)
		color_1(m);
	else if (m->color == 2)
		color_2(m);
}

void	ft_mandelbrot(t_env *e, t_mandelbrot m)
{
	while (++m.p.x < m.img_x)
	{
		while (++m.p.y < m.img_y)
		{
			m.cr = m.p.x / m.zoom_x + m.x1;
			m.ci = m.p.y / m.zoom_y + m.y1;
			m.zr = 0;
			m.zi = 0;
			m.i = -1;
			while (m.zr * m.zr + m.zi * m.zi < 4 && ++m.i < m.it_max)
			{
				m.tmp = m.zr;
				m.zr = m.zr * m.zr - m.zi * m.zi + m.cr;
				m.zi = 2 * m.zi * m.tmp + m.ci;
			}
			color_point(&m);
			put_pixel(&m.p, e);
		}
		m.p.y = 0;
	}
	mlx_put_image_to_window(e->data, e->win, e->img, 0, 0);
}
