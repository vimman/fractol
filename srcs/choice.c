#include "fractol.h"

void	draw(t_env *e,void (*fractal)(t_fractal *m))
{
	while (++e->m.p.x < e->m.img_x)
	{
		while (++e->m.p.y < e->m.img_y)
		{
			fractal(&e->m);
			color_point(&e->m);
			put_pixel(&e->m.p, e);
		}
		e->m.p.y = 0;
	}
	mlx_put_image_to_window(e->data, e->win, e->img, 0, 0);
}

void	change_color(t_env *e)
{
	if (e->m.color < 3)
		e->m.color++;
	else
		e->m.color = 1;
	mlx_clear_window(e->mlx, e->win);
	init_point(&e->m.p);
	if (e->m.type == JULIA)
		draw(e, ft_julia);
}

int		choice(char *arg, t_env *e)
{
	if (!ft_strcmp(arg, "newton"))
	{
		newton_init(&e->m);
		draw(e, ft_newton);
	}
	if (!ft_strcmp(arg, "julia"))
	{
		julia_init(&e->m);
		draw(e, ft_julia);
	}
	if (!ft_strcmp(arg, "mandelbrot"))
	{
		mandel_init(&e->m);
		draw(e, ft_mandelbrot);
	}
	return (0);
}
