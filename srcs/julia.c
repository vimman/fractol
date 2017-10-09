#include "fractol.h"

void	julia_init(t_fractal *f)
{
	f->type = JULIA;
	f->text = 0;
	f->stop = 0;
	f->x1 = -3.2;
	//f->x2 = 2;
	f->y1 = -2;
	//f->y2 = 1.2;
	f->cr = 0.285;
	f->ci = 0.01;
	f->zoom = 200;
	f->it_max = 26;
	f->color = 5;
	f->offset_x = 0;
	f->offset_y = 0;
	init_point(&f->p);
}

void	ft_julia(t_fractal *f)
{
	f->zr = f->p.x / f->zoom + f->x1 - f->offset_x;
	f->zi = f->p.y / f->zoom + f->y1 - f->offset_y;
	f->i = 0;
	while (f->zr * f->zr + f->zi * f->zi < 4 && ++f->i < f->it_max)
	{
		f->tmp = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2 * f->zi * f->tmp + f->ci;
	}
}
