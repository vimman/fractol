#include "fractol.h"

void	text(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "iterations");
	mlx_string_put(e->mlx, e->win, 150, 10, 0xFFFFFF, ft_itoa(e->f.it_max));

	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "color");
	mlx_string_put(e->mlx, e->win, 150, 30, 0xFFFFFF, ft_itoa(e->f.color));

	
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF, "zoom");
	mlx_string_put(e->mlx, e->win, 150, 50, 0xFFFFFF, ft_itoa(e->f.zoom));


	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF, "offset_x");
	mlx_string_put(e->mlx, e->win, 150, 70, 0xFFFFFF, ft_itoa(e->f.offset_x));


	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF, "offset_y");
	mlx_string_put(e->mlx, e->win, 150, 90, 0xFFFFFF, ft_itoa(e->f.offset_y));
}

void	tg_text(t_env *e)
{
	e->f.text ? (e->f.text = 0) : (e->f.text = 1);
	redraw(e);
}
