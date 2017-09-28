#include "fractol.h"

int		quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void	stop_mov(t_env *e)
{
	if (e->m.type == JULIA)
		e->m.type = 0;
	else if (e->m.type == 0)
		e->m.type = JULIA;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		quit(e);
	if (keycode == 8)
		change_color(e);
	if (keycode == 49)
		stop_mov(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)button;
	(void)x;
	(void)y;
	(void)e;
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	return (0);
}

int		move(int x, int y, t_env *e)
{
	if (e->m.type == JULIA)
	{
		e->m.cr = 0.004 * (-x + WIDTH / 2);
		e->m.ci = 0.002 * (-y + HEIGHT / 2);
		mlx_clear_window(e->mlx, e->win);
		init_point(&e->m.p);
		draw(e, ft_julia);
	}
	return (0);
}

