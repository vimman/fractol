#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <X.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_keys.h"

#include <stdio.h>																	//printf();

# define WIDTH 1280
# define HEIGHT 800

# define GREEN	0x009688
# define YELLOW	0xfeff77
# define BLUE	0x4162ff
# define PINK	0xff0097
# define WHITE	0xFFFFFF
# define BROWN	0x654432

# define JULIA	1
# define MANDEL	2
# define NEWTON	3
# define BURN	4

typedef struct			s_col
{
	double	freq1;
	double	freq2;
	double	freq3;
	double	phas1;
	double	phas2;
	double	phas3;
	int		center;
	int		width;
	int		len;
}						t_col;

typedef struct			s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}						t_point;

typedef struct			s_thread
{
}						t_thread;

typedef struct			s_fractal
{
	int		type;
	int		stop;
	int		text;
	int		color;
	t_point	p;
	long	i;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	it_max;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	double	n1;
	double	n2;
	t_col	c;
}						t_fractal;

typedef struct			s_env
{
	void		*mlx;
	void		*win;
	t_point		origin;
	int			color;

	void		*img;
	int			*data;
	int			size;
	int			bpp;
	int			endian;

	t_fractal	f;
}						t_env;

void					mov_phaze(int keycode, t_env *e);
void					hooks(t_env *e);
void					usage(void);
void					text(t_env *e);
void					tg_text(t_env *e);
void					iter(int keycode, t_env *e);
void					change(int keycode, t_env *e);
void					init_triangle(t_fractal *f);
void					triangle(t_fractal *f);
void					burn_init(t_fractal *f);
void					ft_burn(t_fractal *f);
void					reset(t_env *e);
void					set(t_env *e);
int						quit(t_env *e);
void					redraw(t_env *e);
void					init_img(t_env *e);
void					color_1(t_fractal *f);
int						expose_hook(t_env *e);
void					change_color(t_env *e);
void					ft_julia(t_fractal *f);
void					init_point(t_point *p);
void					ft_newton(t_fractal *f);
void					julia_init(t_fractal *j);
int						init(t_env *e, char *arg);
void					mandel_init(t_fractal *f);
void					color_point(t_fractal *f);
void					newton_init(t_fractal *f);
void					color_point(t_fractal *f);
void					move(int keycode, t_env *e);
void					ft_mandelbrot(t_fractal *f);
int						choice(char *arg, t_env *e);
int						mmove(int x, int y, t_env *e);
void					put_pixel(t_point *p, t_env *e);
int						key_hook(int keycode, t_env *e);
int						drag(int button, int x, int y, t_env *e);
void					zoom(t_env *e, int x, int y, double ratio);
void					draw(t_env *e, void (*fractal)(t_fractal *f));
int						mouse_hook(int button, int x, int y, t_env *e);
int						mlx_hook(void *win_ptr, int x_event, int x_mask,
						int (*funct)(), void *param);

#endif
