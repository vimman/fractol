#include "fractol.h"

int		choice(char *arg, t_env *e)
{
	if (!ft_strcmp(arg, "newton"))
	{
		newton_init(&e->f);
		draw(e, ft_newton);
	}
	else if (!ft_strcmp(arg, "julia"))
	{
		julia_init(&e->f);
		draw(e, ft_julia);
	}
	else if (!ft_strcmp(arg, "mandelbrot"))
	{
		mandel_init(&e->f);
		draw(e, ft_mandelbrot);
	}
	else if (!ft_strcmp(arg, "burningship"))
	{
		burn_init(&e->f);
		draw(e, ft_burn);
	}
	else
		exit(0);
	return (0);
}
