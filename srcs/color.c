#include "fractol.h"

void	mov_phaze(int keycode, t_env *e)
{
	if (keycode == KEY_COMMA)
	{
		e->f.c.phas1 += 0.1;
		e->f.c.phas2 += 0.2;
		e->f.c.phas3 += 0.3;
	}
	else
	{
		e->f.c.phas1 -= 0.1;
		e->f.c.phas2 -= 0.2;
		e->f.c.phas3 -= 0.3;
	}
	redraw(e);
}

int		rgb2int(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

int		sinwave(t_col *c, double i)
{
	int	r;
	int	g;
	int	b;

	r = sin(c->freq1 * i + c->phas1) * c->width + c->center;
	g = sin(c->freq2 * i + c->phas2) * c->width + c->center;
	b = sin(c->freq3 * i + c->phas3) * c->width + c->center;
	return (rgb2int(r, g, b));
}

void	color_1(t_fractal *f)
{
	if (f->i == f->it_max)
		f->p.color = YELLOW * f->zr * f->zi * f->cr * f->ci;
	else
		f->p.color = f->i * 255 / f->it_max * 4;
}

void	color_2(t_fractal *f)
{
	if (f->i == f->it_max)
		f->p.color = WHITE * f->zr * f->zi;
	else
		f->p.color = f->i * 16581375 / f->it_max * 5;
}

void	color_3(t_fractal *f)
{
	if (f->i == f->it_max)
		f->p.color = WHITE;
	else
		f->p.color = f->i * 255 / f->it_max;
}

void	color_4(t_fractal *f)
{
	if (f->i == f->it_max)
		f->p.color = f->zi / f->zr;
	else
		f->p.color = f->i * (255 * 255 * 255) / (f->cr / f->ci + f->zr / f->zi);
}

void	color_5(t_fractal *f)
{
	if (f->i == f->it_max)
		f->p.color = f->zi / f->zr;
	else
		f->p.color = f->i * BLUE;
}

void	color_6(t_fractal *f)
{
	if (f->i == f->it_max)
		f->p.color = rgb2int(0, 0, 0);
	else
		f->p.color = f->i * rgb2int(255, 150, 0) / (f->zi * f->zr / 10);
}

void	color_7(t_fractal *f)
{
	t_col	c;
	double	zn;
	double	continuous_index;

	c.freq1 = 0.1;
	c.freq2 = 0.1;
	c.freq3 = 0.1;
	//c.phas1 = 4;
	//c.phas2 = 6;
	//c.phas3 = 8;
	c.center = 200;
	c.width = 55;
	zn = sqrt(f->zr * f->zr + f->zi * f->zi);
	continuous_index = f->i + 1 + (log(2) / zn) / log(2);
	if (f->i == f->it_max)
		f->p.color = 0;
	else
		f->p.color = sinwave(&c, continuous_index);
}

void	color_8(t_fractal *f)
{
	t_col	c;
	double	zn;
	double	continuous_index;

	c.freq1 = 0.7;
	c.freq2 = 0.7;
	c.freq3 = 0.7;
	//c.phas1 = 5;
	//c.phas2 = 6;
	//c.phas3 = 9;
	c.center = 150;
	c.width = 100;
	zn = sqrt(f->zr * f->zr - f->zi * f->zi);
	continuous_index = f->i + 1 - (log(2) / zn) / log(2);
	if (f->i == f->it_max)
		f->p.color = 0;
	else
		f->p.color = sinwave(&c, continuous_index);
}

void	color_9(t_fractal *f)
{
	double	zn;
	double	continuous_index;

	f->c.freq1 = 2.4;
	f->c.freq2 = 2.4;
	f->c.freq3 = 2.4;
	//f->c.phas1 = 7;
	//f->c.phas2 = 9;
	//f->c.phas3 = 11;
	f->c.center = 200;
	f->c.width = 55;
	zn = sqrt(f->zr * f->zr + f->zi * f->zi);
	continuous_index = f->i + 1 + (log(2) / zn) / log(2);
	if (f->i == f->it_max)
		f->p.color = 0;
	else
		f->p.color = sinwave(&f->c, continuous_index);
}

void	color_point(t_fractal *f)
{
	if (f->color == 1)
		color_1(f);
	else if (f->color == 2)
		color_2(f);
	else if (f->color == 3)
		color_3(f);
	else if (f->color == 4)
		color_4(f);
	else if (f->color == 5)
		color_5(f);
	else if (f->color == 6)
		color_6(f);
	else if (f->color == 7)
		color_7(f);
	else if (f->color == 8)
		color_8(f);
	else if (f->color == 9)
		color_9(f);
}

void	change_color(t_env *e)
{
	if (e->f.color < 9)
		e->f.color++;
	else
		e->f.color = 1;
	redraw(e);
}
