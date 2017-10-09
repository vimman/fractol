#include "fractol.h"

void	usage(void)
{
	ft_putstr_fd("Usage: ./fractol [julia | mandelbrot ", 2); 
	ft_putendl_fd("| newton | burningship]", 2);
	exit(0);
}
