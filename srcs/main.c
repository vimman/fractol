#include "fractol.h"

void	init_point(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
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
	e->scale = (e->win_width / e->o.width + e->win_height / e->o.height) / 4;
	e->origin.x = (e->win_width / 2) - ((e->o.width * e->scale) / 2);
	e->origin.y = (e->win_height / 2) - ((e->o.height * e->scale) / 2);
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "win");
	e->o.pitch = 1;
	e->o.bres = 1;
	e->o.iso = 1;
	e->alt = 0;
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
		sleep(0);
	if (init(&e) < 0)
		return (-1);
	mlx_hook(e.win, 17, (1L << 17), quit, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
