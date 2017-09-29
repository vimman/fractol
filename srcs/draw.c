#include "fractol.h"

void	draw(t_env *e,void (*fractal)(t_fractal *m))
{
	while (++e->m.p.x < WIDTH)
	{
		while (++e->m.p.y < HEIGHT)
		{
			fractal(&e->m);
			color_point(&e->m);
			put_pixel(&e->m.p, e);
		}
		e->m.p.y = 0;
	}
	mlx_put_image_to_window(e->data, e->win, e->img, 0, 0);
}
