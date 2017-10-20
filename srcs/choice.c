/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:53:27 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:53:29 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (keycode == KEY_5)
		multi_init(&e->f);
	if (keycode == KEY_6)
		juliux_init(&e->f);
	if (keycode == KEY_7)
		celtic_init(&e->f);
	if (keycode == KEY_8)
		bird_init(&e->f);
	redraw(e);
}

int		choice(char *arg, t_env *e)
{
	if (!ft_strcmp(arg, "newton"))
		newton_init(&e->f);
	else if (!ft_strcmp(arg, "julia"))
		julia_init(&e->f);
	else if (!ft_strcmp(arg, "mandelbrot"))
		mandel_init(&e->f);
	else if (!ft_strcmp(arg, "burningship"))
		burn_init(&e->f);
	else if (!ft_strcmp(arg, "multibrot"))
		multi_init(&e->f);
	else if (!ft_strcmp(arg, "juliux"))
		juliux_init(&e->f);
	else if (!ft_strcmp(arg, "celtic"))
		celtic_init(&e->f);
	else if (!ft_strcmp(arg, "bird"))
		bird_init(&e->f);
	redraw(e);
	return (0);
}
