#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
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

typedef union			s_col
{
	char	c[4];
	int		co;
}						t_col;

typedef struct			s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}						t_point;

typedef struct			s_fractal
{
	int		type;
	int		stop;
	int		color;
	t_point	p;
	long	i;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	img_x;
	double	img_y;
	double	it_max;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	double	zoom;
	double	zoom_x;
	double	zoom_y;
	double	mouse_x;
	double	mouse_y;
	//int		basex;
	//int		basey;
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

	t_fractal	m;
}						t_env;

void					reset(t_env *e);
void					set(t_env *e);
int						quit(t_env *e);
void					redraw(t_env *e);
void					init_img(t_env *e);
void					color_1(t_fractal *m);
int						expose_hook(t_env *e);
void					change_color(t_env *e);
void					ft_julia(t_fractal *m);
void					init_point(t_point *p);
void					ft_newton(t_fractal *m);
void					julia_init(t_fractal *j);
int						init(t_env *e, char *arg);
void					mandel_init(t_fractal *m);
void					color_point(t_fractal *m);
void					newton_init(t_fractal *m);
void					color_point(t_fractal *m);
void					move(int keycode, t_env *e);
void					ft_mandelbrot(t_fractal *m);
int						choice(char *arg, t_env *e);
int						mmove(int x, int y, t_env *e);
void					put_pixel(t_point *p, t_env *e);
int						key_hook(int keycode, t_env *e);
int						drag(int button, int x, int y, t_env *e);
void					zoom(t_env *e, int x, int y, double ratio);
void					draw(t_env *e,void (*fractal)(t_fractal *m));
int						mouse_hook(int button, int x, int y, t_env *e);
int						mlx_hook(void *win_ptr, int x_event, int x_mask,
						int (*funct)(), void *param);

#endif
