/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:53:55 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:53:56 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, int color, t_env *e)
{
	if (y < HEIGHT && x < WIDTH &&
			y >= 0 && x >= 0)
		e->data[y * WIDTH + x] = color;
}

void	init_point(t_point *p)
{
	p->x = -1;
	p->y = -1;
	p->z = -1;
	p->color = 0xFFFFFF;
}

int		init(t_env *e, char *arg)
{
	char	*title;

	title = ft_strjoin("Fractol          o_O         ", arg);
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, title);
	free(title);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size, &e->endian);
	return (0);
}

void	reset(t_env *e)
{
	if (e->f.type == NEWTON)
		choice("newton", e);
	else if (e->f.type == MANDEL)
		choice("mandelbrot", e);
	else if (e->f.type == JULIA)
		choice("julia", e);
	else if (e->f.type == BURN)
		choice("burningship", e);
	else if (e->f.type == MULTI)
		choice("multibrot", e);
	else if (e->f.type == JULIUX)
		choice("juliux", e);
	else if (e->f.type == CELTIC)
		choice("celtic", e);
	else if (e->f.type == BIRD)
		choice("bird", e);
}

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc < 2 || argc > 2)
		usage(0);
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "newton") &&
			ft_strcmp(argv[1], "julia") &&
			ft_strcmp(argv[1], "mandelbrot") &&
			ft_strcmp(argv[1], "burningship") &&
			ft_strcmp(argv[1], "multibrot") &&
			ft_strcmp(argv[1], "juliux") &&
			ft_strcmp(argv[1], "celtic") &&
			ft_strcmp(argv[1], "bird"))
			usage(0);
		if (init(&e, argv[1]) < 0)
			usage(1);
		choice(argv[1], &e);
	}
	hooks(&e);
}
