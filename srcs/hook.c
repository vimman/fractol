/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:53:44 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:53:47 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter(int keycode, t_env *e)
{
	if (keycode == KEY_OPEN_BRACKET)
	{
		e->f.it_max--;
		if (e->f.it_max == 0)
			e->f.it_max--;
	}
	else
	{
		e->f.it_max++;
		if (e->f.it_max == 0)
			e->f.it_max++;
	}
	redraw(e);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		quit(e);
	else if (keycode == KEY_C)
		change_color(e);
	else if (keycode == KEY_T)
		tg_text(e);
	else if (keycode == KEY_Z)
		tg_it_zoom(e);
	else if (keycode == KEY_SPACEBAR)
		stop_mov(e);
	else if (keycode == KEY_BACKSPACE)
		reset(e);
	else if (keycode == KEY_MINUS || keycode == KEY_EQUAL)
		key_zoom(keycode, e);
	else if (keycode >= KEY_1 && keycode <= KEY_0)
		change(keycode, e);
	else if (keycode == KEY_COMMA || keycode == KEY_DOT)
		mov_phaze(keycode, e);
	else if (keycode == KEY_DOWN || keycode == KEY_UP ||
			keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move(keycode, e);
	else if (keycode == KEY_OPEN_BRACKET || keycode == KEY_CLOSE_BRACKET)
		iter(keycode, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
		drag(button, x, y, e);
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
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, key_hook, e);
	mlx_hook(e->win, MOTIONNOTIFY, POINTERMOTIONMASK, mmove, e);
	mlx_hook(e->win, BUTTONRELEASE, 0, drop, e);
	mlx_hook(e->win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, quit, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
