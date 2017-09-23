#include "fractol.h"

int		quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		quit(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)button;
	(void)e;
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	return (0);
}
