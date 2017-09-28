#include "fractol.h"

void	put_pixel(t_point *p, t_env *e)
{
	if (p->y < e->win_height && p->x < e->win_width &&
		p->y >= 0 && p->x >= 0)
		e->data[p->y * e->win_width + p->x] = p->color;
}

void	init_point(t_point *p)
{
	p->x = -1;
	p->y = -1;
	p->z = -1;
	p->color = 0xFFFFFF;
}

void	init_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_width, e->win_height);
	e->data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size, &e->endian);
}

int		init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win_width = WIDTH;
	e->win_height = HEIGHT;
	e->m.movx = 1;
	e->m.movy = 1;
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "win");
	e->color = 0xFFFFFF;
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc < 2 || argc > 2)
		return (-1);
	if (!ft_strcmp(argv[1], "/dev/random") ||
		!ft_strcmp(argv[1], "/dev/urandom"))
		return (-1);
	if (argc == 2)
	{
		if (init(&e) < 0)
			return (-1);
		init_img(&e);
		choice(argv[1], &e);
	}
	mlx_hook(e.win, 6, 0, move, &e);
	mlx_hook(e.win, 17, (1L << 17), quit, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
