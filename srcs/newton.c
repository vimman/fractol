#include "fractol.h"

void	newton_init(t_fractal *f)
{
	f->text = 0;
	f->x1 = -2;
	f->x2 = 2;
	f->y1 = -2;
	f->y2 = 2;
	f->it_max = 17;
	f->color = 3;
	f->n1 = 3;
	f->n2 = 3;
	f->type = NEWTON;
	init_point(&f->p);
}

void	ft_newton(t_fractal *f)
{
	f->zr = f->p.x * (f->x2 - f->x1) / WIDTH + f->x1;
	f->zi = f->p.y * (f->y2 - f->y1) / HEIGHT + f->y1;
	f->i = 0;
	f->tmp = 1.0;
	while (f->tmp > 0.000001 && ++f->i < f->it_max)
	{
		f->cr = f->zr;
		f->ci = f->zi;
		f->tmp = (f->zr * f->zr + f->zi * f->zi)
			* (f->zr * f->zr + f->zi * f->zi);
		f->zr = (2 * f->zr * f->tmp + f->zr * f->zr
				- f->zi * f->zi) / (f->n1 * f->tmp);
		f->zi = (2 * f->zi * (f->tmp - f->cr)) / (f->n2 * f->tmp);
		f->tmp = (f->zr - f->cr) * (f->zr - f->cr) *
			(f->zi - f->ci) / (f->zi - f->ci);
	}
}
