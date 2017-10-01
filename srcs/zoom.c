#include "fractol.h"

void	zoom(t_env *e, int x, int y, float ratio)
{
	double	x_delta;
	double	y_delta;

	x_delta = (x - WIDTH / 2) * e->m.zoom;
	y_delta = (y - HEIGHT / 2) * e->m.zoom;


	e->m.x1 += x_delta * ratio / WIDTH;
	e->m.y1 += y_delta * ratio / HEIGHT;

	e->m.x2 += x_delta * ratio / WIDTH;
	e->m.y2 += y_delta * ratio / HEIGHT;

	e->m.zoom *= ratio;

	e->m.zoom_x = e->m.zoom * e->m.img_x / (e->m.x2 - e->m.x1);
	e->m.zoom_y = e->m.zoom * e->m.img_y / (e->m.y2 - e->m.y1);
	(void)x;
	(void)y;
	(void)ratio;
	(void)e;
}
