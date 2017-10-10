#include "fractol.h"

void	mandel_init(t_fractal *f)
{
	f->type = MANDEL;
	f->text = 0;
	f->x1 = -3.36;
	f->x2 = 3.36;
	f->y1 = -2.1;
	f->y2 = 2.1;
	f->it_max = 42;
	f->color = 9;
	init_point(&f->p);
}

void	ft_mandelbrot(t_fractal *f)
{
	f->cr = f->p.x * (f->x2 - f->x1) / WIDTH + f->x1;
	f->ci = f->p.y * (f->y2 - f->y1) / HEIGHT + f->y1;
	f->zr = 0;
	f->zi = 0;
	f->i = -1;
	while (f->zr * f->zr + f->zi * f->zi < 4 && ++f->i < f->it_max)
	{
		f->tmp = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2 * f->zi * f->tmp + f->ci;
	}
}
