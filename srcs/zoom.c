#include "fractol.h"

void	zoom(t_env *e, int x, int y, float size)
{
//	double	x_delta;
//	double	y_delta;
//
//	x_delta = (x - WIDTH / 2) * size;
//	y_delta = (y * - HEIGHT / 2) * size;
//
//	e->m.y1 = 2 * e->m.x1 * e->m.y1 + e->m.y1;
//	e->m.x1 = e->m.x2 - e->m.y2 + e->m.x1;
//	e->m.x2 = e->m.x1 * e->m.x1;
//	e->m.y2 = e->m.y1 * e->m.y1;
	//e->m.x1 *= -x + WIDTH / 2;
	//e->m.x2 *= 1.1;
	//e->m.y1 *= 1.1;
	//e->m.y2 *= 1.1;
	e->m.zoom *= size;
	(void)x;
	(void)y;
	(void)size;
	(void)e;
}
