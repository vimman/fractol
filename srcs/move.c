#include "fractol.h"

static void	move_l(t_env *e)
{
	e->m.x1 -= 0.1 / e->m.zoom;
	e->m.x2 -= 0.1 / e->m.zoom;
}

static void	move_r(t_env *e)
{
	e->m.x1 += 0.1 / e->m.zoom;
	e->m.x2 += 0.1 / e->m.zoom;
}

static void	move_d(t_env *e)
{
	e->m.y1 += 0.1 / e->m.zoom;
	e->m.y2 += 0.1 / e->m.zoom;
}

static void	move_u(t_env *e)
{
	e->m.y1 -= 0.1 / e->m.zoom;
	e->m.y2 -= 0.1 / e->m.zoom;
}

int			drag(int button, int x, int y, t_env *e)
{
//	e->m.basex = x;
//	e->m.basey = y;
// Ca marche pas TODO
	printf("drag\n");
	printf("button\t: %d\n", button);
	printf("x\t: %d\n", x);
	printf("y\t: %d\n", y);
	//printf("basex\t: %d\n", e->m.basex);
	//printf("basey\t: %d\n", e->m.basey);

//	e->m.x1 += (e->m.basex - x) / 10 * e->m.x1;
//	e->m.y1 += (e->m.basey - y) / 10 * e->m.y1;
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
	//e->m.x1 += (e->m.basex - x) / 10 * e->m.x1;
	//e->m.y1 += (e->m.basey - y) / 10 * e->m.y1;
	//redraw(e);
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
	redraw(e);
}
