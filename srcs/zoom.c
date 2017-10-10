#include "fractol.h"

void	zoom(t_env *e, int x, int y, double ratio)
{
	double	x_curs;
	double	y_curs;

	x_curs = (x * (e->f.x2 - e->f.x1)) / WIDTH + e->f.x1;
	y_curs = (y * (e->f.y2 - e->f.y1)) / HEIGHT + e->f.y1;

	e->f.x1 = x_curs - (((x_curs - e->f.x1) / ratio));
	e->f.y1 = y_curs - (((y_curs - e->f.y1) / ratio));
	e->f.x2 = x_curs - (((x_curs - e->f.x2) / ratio));
	e->f.y2 = y_curs - (((y_curs - e->f.y2) / ratio));
}
