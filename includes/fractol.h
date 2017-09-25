#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 1280
# define HEIGHT 800

# define GREEN	0x009688
# define YELLOW	0xfeff77
# define BLUE	0x4162ff
# define PINK	0xff0097
# define WHITE	0xFFFFFF
# define BROWN	0x654432

typedef struct			s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}						t_point;

typedef struct			s_env
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_point		origin;
	int			color;

	void		*img;
	int			*data;
	int			size;
	int			bpp;
	int			endian;
}						t_env;

typedef struct			s_julia
{
	t_point	p;
	double	c_re;
	double	c_im;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	zoom;
	double	movex;
	double	movey;
	int		color;
	int		maxit;
}						t_julia;

typedef struct			s_mandelbrot
{
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
}						t_mandelbrot;

void					set(t_env *e);
int						quit(t_env *e);
int						init(t_env *e);
void					init_img(t_env *e);
int						ft_julia(t_env *e);
int						expose_hook(t_env *e);
void					init_point(t_point *p);
void					ft_mandelbrot(t_env *e);
int						choice(char *arg, t_env *e);
void					put_pixel(t_point *p, t_env *e);
int						key_hook(int keycode, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
int						mlx_hook(void *win_ptr, int x_event, int x_mask,
						int (*funct)(), void *param);

#endif
