#include "fractol.h"

int		ft_julia(t_env *e)
{
	(void)e;
	return (0);
}

int		ft_mandelbrot(t_env *e)
{
	t_mandelbrot	m;

	m.it_max = 50;
	init_point(&m.p);
	while (m.p.x < e->win_width)
	{
		while (m.p.y < e->win_height)
		{
			m.cr = m.p.x;
			m.ci = m.p.y;
			m.zr = 0;
			m.zi = 0;
			m.i = 0;
			while (m.zr * m.zr + m.zi * m.zi < 4 && m.i < m.it_max)
			{
				m.zr = m.zr * m.zr - m.zi * m.zi + m.ci;
				m.zi = 2 * m.zr * m.zi + m.ci;
				m.i++;
			}
			if (m.i == m.it_max)
				put_pixel(&m.p, e);
			m.p.y++;
		}
		m.p.x++;
	}
	return (0);
}

int		choice(char *arg, t_env *e)
{
	if (!ft_strcmp(arg, "julia"))
	{
		ft_julia(e);
		return (1);
	}
	if (!ft_strcmp(arg, "mandelbrot"))
	{
		ft_mandelbrot(e);
		return (1);
	}
	return (0);
}
