#include "fractol.h"

int		quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void	stop_mov(t_env *e)
{
	if (e->m.stop == 0)
		e->m.stop = 1;
	else if (e->m.stop == 1)
		e->m.stop = 0;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		quit(e);
	if (keycode == 8)
		change_color(e);
	if (keycode == 49)
		stop_mov(e);
	if (keycode >= 123 && keycode <= 126)
		move(keycode, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
		zoom(e, x, y, 1.1);
	else if (button == 5)
		zoom(e, x, y, 0.9);
	ft_putnbr(button);
	redraw(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	return (0);
}

int		mmove(int x, int y, t_env *e)
{
	if (e->m.stop)
		if (e->m.type == JULIA)
		{
			e->m.cr = 0.004 * (-x + WIDTH / 2);
			e->m.ci = 0.002 * (-y + HEIGHT / 2);
			draw(e, ft_julia);
		}
	return (0);
}
