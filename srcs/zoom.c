#include "fractol.h"

double	modulus(double a, double b)
{
	return (sqrt(a * a + b * b));
}

void	zoom(t_env *e, int x, int y, double ratio)
{
	//double	x_delta;
	//double	y_delta;
	//x_delta = (x / (WIDTH + x));
	//y_delta = (y / (HEIGHT + y));
	//e->f.x1 += e->f.x1 / (WIDTH / 2);
	//e->f.y1 += e->f.y1 / (HEIGHT / 2);
	//e->f.x2 += e->f.x2 / (WIDTH / 2);
	//e->f.y2 += e->f.y2 / (HEIGHT / 2);
	//printf("zoom\t%f\n", e->f.zoom);
	//printf("x_delta\t%f\n", x_delta);
	(void)x;
	(void)y;

	if (e->f.type == MANDEL || e->f.type == BURN)
	{
		if (ratio > 1)
		{
			e->f.x1 = (WIDTH / 2 * e->f.x1) / (WIDTH);
			e->f.y1 = (HEIGHT / 2 * e->f.y1) / (HEIGHT);
			e->f.x2 = (WIDTH / 2 * e->f.x2) / (WIDTH);
			e->f.y2 = (HEIGHT / 2 * e->f.y2) / (HEIGHT);
		}
		else
		{
			e->f.x1 = (WIDTH * e->f.x1) / (WIDTH / 2);
			e->f.y1 = (HEIGHT * e->f.y1) / (HEIGHT / 2);
			e->f.x2 = (WIDTH * e->f.x2) / (WIDTH / 2);
			e->f.y2 = (HEIGHT * e->f.y2) / (HEIGHT / 2);
		}
	e->f.zoom_x = e->f.zoom * e->f.img_x / (e->f.x2 - e->f.x1);
	e->f.zoom_y = e->f.zoom * e->f.img_y / (e->f.y2 - e->f.y1);
	}
	else 
		e->f.zoom *= ratio;
}
