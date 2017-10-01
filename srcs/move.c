#include "fractol.h"

static void	move_l(t_env *e)
{
	e->m.x1 *= 0.9;
	e->m.x2 *= 0.9;
}

static void	move_r(t_env *e)
{
	e->m.x1 *= 1.1;
	e->m.x2 *= 1.1;
}

static void	move_d(t_env *e)
{
	e->m.y1 *= 1.1;
	e->m.y2 *= 1.1;
}

static void	move_u(t_env *e)
{
	e->m.y1 *= 0.9;
	e->m.y2 *= 0.9;
}

int			drag(int button, int x, int y, t_env *e)
{
	int		basex;
	int		basey;

	basex = x;
	basey = y;
// Ca marche pas TODO
	printf("%d\n", button);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", basex);
	printf("%d\n", basey);

	e->m.x1 += (basex - x) / 10 * e->m.x1;
	e->m.y1 += (basey - y) / 10 * e->m.y1;
	redraw(e);
	return (0);
}

void		move(int keycode, t_env *e)
{
	if (keycode == 123)
		move_l(e);
	else if (keycode == 124)
		move_r(e);
	else if (keycode == 125)
		move_d(e);
	else if (keycode == 126)
		move_u(e);
	redraw(e); }
