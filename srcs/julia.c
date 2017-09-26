#include "fractol.h"

void	julia_init(t_mandelbrot *m)
{ 
	m->x1 = -3.2;
	m->x2 = 2;
	m->y1 = -2;
	m->y2 = 1.2;
	m->zoom = 200;
	m->it_max = 130;
	m->img_x = (m->x2 - m->x1) * m->zoom;
	m->img_y = (m->x2 - m->x1) * m->zoom;
	m->color = 2;
	init_point(&m->p);
}

void	ft_julia(t_env *e, t_mandelbrot m)
{
	while (++m.p.x < m.img_x)
	{
		while (++m.p.y < m.img_y)
		{
			m.cr = 0.285;
			m.ci = 0.01;
			m.zr = m.p.x / m.zoom + m.x1;
			m.zi = m.p.y / m.zoom + m.y1;
			m.i = 0;
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

int		choice(char *arg, t_env *e)
{
	if (!ft_strcmp(arg, "julia"))
	{
		t_mandelbrot		j;

		julia_init(&j);
		ft_julia(e, j);
		return (1);
	}
	if (!ft_strcmp(arg, "mandelbrot"))
	{
		t_mandelbrot	m;

		mandel_init(&m);
		ft_mandelbrot(e, m);
		return (1);
	}
	return (0);
}
