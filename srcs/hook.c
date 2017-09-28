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
	if (keycode == 7)
		change_color(e);
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
	if (e->m.type == 1)
	{
		e->m.movx = x;
		e->m.movy = y;
		mlx_clear_window(e->mlx, e->win);
		julia_init(&e->m);
		draw(e, ft_julia);
	}
	return (0);
}

