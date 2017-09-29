#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

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
	int		color;
	t_point	p;
	long	i;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom;
	double	img_x;
	double	img_y;
	double	it_max;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	double	zoom_x;
	double	zoom_y;
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

void					change_color(t_env *e);
void					draw(t_env *e,void (*fractal)(t_fractal *m));
int						move(int x, int y, t_env *e);
void					color_point(t_fractal *m);
void					newton_init(t_fractal *m);
void					ft_newton(t_fractal *m);
void					color_point(t_fractal *m);
void					ft_julia(t_fractal *m);
void					julia_init(t_fractal *j);
void					color_1(t_fractal *m);
void					ft_mandelbrot(t_fractal *m);
void					mandel_init(t_fractal *m);
void					set(t_env *e);
int						quit(t_env *e);
int						init(t_env *e);
void					init_img(t_env *e);
int						expose_hook(t_env *e);
void					init_point(t_point *p);
int						choice(char *arg, t_env *e);
void					put_pixel(t_point *p, t_env *e);
int						key_hook(int keycode, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
int						mlx_hook(void *win_ptr, int x_event, int x_mask,
						int (*funct)(), void *param);

#endif
