#include "fractol.h"

int		rgb2int(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

int		sinwave(t_col *c, int i)
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

	c.freq1 = 0.6;
	c.freq2 = 0.6;
	c.freq3 = 0.6;
	c.phas1 = 4;
	c.phas2 = 6;
	c.phas3 = 8;
	c.center = 200;
	c.width = 55;
	if (f->i == f->it_max)
		f->p.color = 0;
	else
		f->p.color = sinwave(&c, f->i);
}

void	color_8(t_fractal *f)
{
	t_col	c;

	c.freq1 = 0.7;
	c.freq2 = 0.7;
	c.freq3 = 0.7;
	c.phas1 = 5;
	c.phas2 = 6;
	c.phas3 = 9;
	c.center = 150;
	c.width = 100;
	if (f->i == f->it_max)
		f->p.color = 0;
	else
		f->p.color = sinwave(&c, f->i);
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
}

void	change_color(t_env *e)
{
	if (e->f.color < 8)
		e->f.color++;
	else
		e->f.color = 1;
	redraw(e);
}
