#include "fractol.h"

void	newton_init(t_mandelbrot *m)
{
	m->x1 = -1.2;
	m->x2 = 1.9;
	m->y1 = -1;
	m->y2 = 3;
	m->zoom = 100;
	m->it_max = 33;
	m->img_x = WIDTH;
	m->img_y = HEIGHT;
	m->color = (t_col)1;
	init_point(&m->p);
}

void	ft_newton(t_env *e)
{
	while (++e->m.p.x < e->m.img_x)
	{
		while (++e->m.p.y < e->m.img_y)
		{
			e->m.zr = (e->m.p.x - WIDTH) / (e->m.zoom * WIDTH);
			e->m.zi = (e->m.p.y - HEIGHT) / (e->m.zoom * HEIGHT);
			e->m.i = 0;
			e->m.tmp = 1.0;
			while (e->m.tmp > 0.000001 && ++e->m.i < e->m.it_max)
			{
				e->m.cr = e->m.zr;
				e->m.ci = e->m.zi;
				e->m.tmp = (e->m.zr * e->m.zr + e->m.zi * e->m.zi)
					* (e->m.zr * e->m.zr + e->m.zi * e->m.zi);
				e->m.zr = (2 * e->m.zr * e->m.tmp + e->m.zr * e->m.zr
						- e->m.zi * e->m.zi) / (3.0 * e->m.tmp);
				e->m.zi = (2 * e->m.zi * (e->m.tmp - e->m.cr)) /
					(3.0 * e->m.tmp);
				e->m.tmp = (e->m.zr - e->m.cr) * (e->m.zr - e->m.cr) +
					(e->m.zi - e->m.ci) * (e->m.zi - e->m.ci);
			}
			color_point(&e->m);
			put_pixel(&e->m.p, e);
		}
		e->m.p.y = 0;
	}
	mlx_put_image_to_window(e->data, e->win, e->img, 0, 0);
}
