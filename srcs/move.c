#include "fractol.h"

static void	move_l(t_env *e)
{
	e->f.x1 -= 0.1;
	e->f.x2 -= 0.1;
}

static void	move_r(t_env *e)
{
	e->f.x1 += 0.1;
	e->f.x2 += 0.1;
}

static void	move_d(t_env *e)
{
	e->f.y1 += 0.1;
	e->f.y2 += 0.1;
}

static void	move_u(t_env *e)
{
	e->f.y1 -= 0.1;
	e->f.y2 -= 0.1;
}

int			drag(int button, int x, int y, t_env *e)
{
//	e->f.basex = x;
//	e->f.basey = y;
// Ca marche pas TODO
	printf("drag\n");
	printf("button\t: %d\n", button);
	printf("x\t: %d\n", x);
	printf("y\t: %d\n", y);
	//printf("basex\t: %d\n", e->f.basex);
	//printf("basey\t: %d\n", e->f.basey);
//	e->f.x1 += (e->f.basex - x) / 10 * e->f.x1;
//	e->f.y1 += (e->f.basey - y) / 10 * e->f.y1;
	redraw(e);
	return (0);
}

int			dmov(int button, int x, int y, t_env *e)
{
	(void)e;
	printf("dmov\n");
	printf("button\t: %d\n", button);
	printf("x\t: %d\n", x);
	printf("y\t: %d\n", y);
	//e->f.x1 += (e->f.basex - x) / 10 * e->f.x1;
	//e->f.y1 += (e->f.basey - y) / 10 * e->f.y1;
	//redraw(e);
	return (0);
}

void		move(int keycode, t_env *e)
{
	if (keycode == KEY_H || keycode == KEY_LEFT)
		move_l(e);
	else if (keycode == KEY_L || keycode == KEY_RIGHT)
		move_r(e);
	else if (keycode == KEY_J || keycode == KEY_DOWN)
		move_d(e);
	else if (keycode == KEY_K || keycode == KEY_UP)
		move_u(e);
	redraw(e);
}

int			mmove(int x, int y, t_env *e)
{
	if (e->f.stop)
		if (e->f.type == JULIA)
		{
			e->f.cr = 0.004 * (-x + WIDTH / 2);
			e->f.ci = 0.002 * (-y + HEIGHT / 2);
			draw(e, ft_julia);
		}
	return (0);
}
