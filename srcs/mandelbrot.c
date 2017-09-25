#include "fractol.h"

void	mandel_init(t_mandelbrot *m)
{
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zoom = 320;
	m->it_max = 44;
	m->img_x = HEIGHT;
	m->img_y = HEIGHT;
	m->zoom_x = m->img_x / (m->x2 - m->x1);
	m->zoom_y = m->img_y / (m->y2 - m->y1);
	init_point(&m->p);
}

void	color_point(t_mandelbrot *m)
{
	if (m->i == m->it_max)
		m->p.color = m->i;
	else
		m->p.color = m->i * 255 * 255 / m->it_max;
}

void	ft_mandelbrot(t_env *e)
{
	t_mandelbrot	m;

	mandel_init(&m);
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
