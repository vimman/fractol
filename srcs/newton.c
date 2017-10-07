#include "fractol.h"

void	newton_init(t_fractal *f)
{
	f->text = 0;
	f->x1 = -1;
	f->x2 = 1;
	f->y1 = -1;
	f->y2 = 1;
	f->zoom = 0.1;
	f->it_max = 17;
	f->img_x = WIDTH;
	f->img_y = HEIGHT;
	f->color = 3;
	f->type = NEWTON;
	init_point(&f->p);
}

void	ft_newton(t_fractal *f)
{
	f->zr = (f->p.x - WIDTH / 2) / (f->zoom * WIDTH);
	f->zi = (f->p.y - HEIGHT / 2) / (f->zoom * HEIGHT);
	f->i = 0;
	f->tmp = 1.0;
	while (f->tmp > 0.000001 && ++f->i < f->it_max)
	{
		f->cr = f->zr;
		f->ci = f->zi;
		f->tmp = (f->zr * f->zr + f->zi * f->zi)
			* (f->zr * f->zr + f->zi * f->zi);
		f->zr = (2 * f->zr * f->tmp + f->zr * f->zr
				- f->zi * f->zi) / (3.0 * f->tmp);
		f->zi = (2 * f->zi * (f->tmp - f->cr)) / (3.0 * f->tmp);
		f->tmp = (f->zr - f->cr) * (f->zr - f->cr) *
			(f->zi - f->ci) / (f->zi - f->ci);
	}
}
