#include "fractol.h"

int		quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void	stop_mov(t_env *e)
{
	if (e->f.stop == 0)
		e->f.stop = 1;
	else if (e->f.stop == 1)
		e->f.stop = 0;
}

void	change(int keycode, t_env *e)
{
	if (keycode == KEY_1)
		julia_init(&e->f);
	if (keycode == KEY_2)
		mandel_init(&e->f);
	if (keycode == KEY_3)
		newton_init(&e->f);
	if (keycode == KEY_4)
		burn_init(&e->f);
	redraw(e);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		quit(e);
	else if (keycode == KEY_C)
		change_color(e);
	else if (keycode == KEY_SPACEBAR)
		stop_mov(e);
	else if (keycode == KEY_H || keycode == KEY_J ||
			keycode == KEY_K || keycode == KEY_L ||
			(keycode >= 123 && keycode <= 126))
		move(keycode, e);
	else if (keycode == KEY_BACKSPACE)
		reset(e);
	else if (keycode >= KEY_1 && keycode <= KEY_0)
		change(keycode, e);
	else if (keycode == KEY_OPEN_BRACKET || keycode == KEY_CLOSE_BRACKET)
		iter(keycode, e);
	else if (keycode == KEY_T)
		tg_text(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
		zoom(e, x, y, 1.1);
	else if (button == 5)
		zoom(e, x, y, 0.9);
	redraw(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	return (0);
}

void	hooks(t_env *e)
{
	mlx_hook(e->win, 6, 0, mmove, e);
	mlx_hook(e->win, 17, (1L << 17), quit, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
