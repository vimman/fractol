#include "fractol.h"

int		ft_julia(t_env *e)
{
	(void)e;
	return (0);
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
