#include "fractol.h"

int		ft_julia(t_env *e)
{
}

int		ft_mandelbrot(t_env *e)
{
	t_point	p;
	double	it_max;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	i;

	it_max = 50;
	init_point(p);
	while (p.x < e->win_width)
	{
		while (p.y < e->win_height)
		{
			cr = p.x;
			ci = p.y;
			zr = 0;
			zi = 0;
			i = 0;
			while (zr * zr + zi * zi < 4 && i < it_max)
			{
				zr = zr * zr - zi * zi + ci;
				zi = 2 * zr * zi + ci;
				i++;
			}
			if (i == it_max)
				put_pixel(&p, e);
			p.y++;
		}
		p.x++;
	}
}

int		choice(char *arg, t_env *e)
{
	if (!ft_strcmp(arg, "julia"))
	{
		ft_julia(e);
		return (1);
	}
	if (!ft_strcmp(arg, "mandelbrot"))
	{
		ft_mandelbrot(e);
		return (1);
	}
	return (0);
}
