#include "fractol.h"

void	change_color(t_env *e)
{
	if (e->m.color < 5)
		e->m.color++;
	else
		e->m.color = 1;
	mlx_clear_window(e->mlx, e->win);
	init_point(&e->m.p);
	if (e->m.type == JULIA)
		draw(e, ft_julia);
	else if (e->m.type == MANDEL)
		draw(e, ft_mandelbrot);
	else if (e->m.type == NEWTON)
		draw(e, ft_newton);
	ft_putendl(ft_itoa(e->m.color));
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
