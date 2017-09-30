#include "fractol.h"

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
