#include "fractol.h"

void	draw(t_env *e, void (*fractal)(t_fractal *m))
{
	mlx_clear_window(e->mlx, e->win);
	init_point(&e->m.p);
	while (++e->m.p.x < WIDTH)
	{
		while (++e->m.p.y < HEIGHT)
		{
			fractal(&e->m);
			color_point(&e->m);
			put_pixel(&e->m.p, e);
		}
		e->m.p.y = 0;
	}
	mlx_put_image_to_window(e->data, e->win, e->img, 0, 0);
}

void	redraw(t_env *e)
{
	if (e->m.type == JULIA)
		draw(e, ft_julia);
	else if (e->m.type == MANDEL)
		draw(e, ft_mandelbrot);
	else if (e->m.type == NEWTON)
		draw(e, ft_newton);
	else if (e->m.type == BURN)
		draw(e, ft_burn);
}
