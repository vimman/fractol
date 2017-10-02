#include "fractol.h"

double	modulus(double a, double b)
{
	return sqrt(a * a + b * b);
}

void	zoom(t_env *e, int x, int y, double ratio)
{
	//double	x_delta;
	//double	y_delta;

	//x_delta = (x / (WIDTH + x));
	//y_delta = (y / (HEIGHT + y));

	//e->m.x1 += e->m.x1 / (WIDTH / 2);
	//e->m.y1 += e->m.y1 / (HEIGHT / 2);
	//e->m.x2 += e->m.x2 / (WIDTH / 2);
	//e->m.y2 += e->m.y2 / (HEIGHT / 2);

	//printf("zoom\t%f\n", e->m.zoom);
	//printf("x_delta\t%f\n", x_delta);
	(void)x;
	(void)y;

	if (e->m.type == MANDEL)
	{
		if (ratio > 1)
		{
			e->m.x1 = (WIDTH / 2 * e->m.x1) / (WIDTH);
			e->m.y1 = (HEIGHT / 2 * e->m.y1) / (HEIGHT);
			e->m.x2 = (WIDTH / 2 * e->m.x2) / (WIDTH);
			e->m.y2 = (HEIGHT / 2 * e->m.y2) / (HEIGHT);
		}
		else
		{
			e->m.x1 = (WIDTH * e->m.x1) / (WIDTH / 2);
			e->m.y1 = (HEIGHT * e->m.y1) / (HEIGHT / 2);
			e->m.x2 = (WIDTH * e->m.x2) / (WIDTH / 2);
			e->m.y2 = (HEIGHT * e->m.y2) / (HEIGHT / 2);
		}
	e->m.zoom_x = e->m.zoom * e->m.img_x / (e->m.x2 - e->m.x1);
	e->m.zoom_y = e->m.zoom * e->m.img_y / (e->m.y2 - e->m.y1);
	}
	else 
		e->m.zoom *= ratio;

}
