#include <fractol.h>

void	burn_init(t_fractal *f)
{
	f->type = BURN;
	f->text = 0;
	f->x1 = -3.36;
	f->x2 = 3.36;
	f->y1 = -2.1;
	f->y2 = 2.1;
	f->zoom = 1.0f;
	f->it_max = 32;
	f->img_x = WIDTH + f->zoom;
	f->img_y = HEIGHT + f->zoom;
	f->zoom_x = f->zoom * f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->zoom * f->img_y / (f->y2 - f->y1);
	f->color = 6;
	init_point(&f->p);
}

void	ft_burn(t_fractal *f)
{
	f->cr = f->p.x / f->zoom_x + f->x1;
	f->ci = f->p.y / f->zoom_y + f->y1;
	f->zr = 0;
	f->zi = 0;
	f->i = -1;
	while (f->zr * f->zr + f->zi * f->zi < 4 && ++f->i < f->it_max)
	{
		f->tmp = f->zi;
		f->zi = fabs((double)(f->zr * f->zi + f->zr * f->zi + f->ci));
		f->zr = fabs((double)(f->zr * f->zr - f->tmp * f->tmp + f->cr));
	}
}
