/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:54:33 by qdurot            #+#    #+#             */
/*   Updated: 2017/10/11 23:54:34 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_keys.h"

# define WIDTH 1280
# define HEIGHT 800

# define KEYPRESS			2
# define KEYPRESSMASK		(1L<<0)
# define MOTIONNOTIFY		6
# define POINTERMOTIONMASK	(1L<<6)
# define BUTTONRELEASE		5
# define BUTTONRELEASEMASK	(1L<<3)
# define DESTROYNOTIFY		17
# define STRUCTURENOTIFYMASK	(1L<<17)

# define GREEN	0x009688
# define YELLOW	0xfeff77
# define BLUE	0x4162ff
# define PINK	0xff0097
# define WHITE	0xFFFFFF
# define BROWN	0x654432
# define RED	0xFF0000

# define JULIA	1
# define MANDEL	2
# define NEWTON	3
# define BURN	4
# define MULTI	5
# define JULIUX	6
# define CELTIC	7
# define BIRD	8

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

typedef struct			s_fractal
{
	int		type;
	int		stop;
	int		it_zoom;
	int		dndrop;
	int		text;
	int		color;
	t_point	p;
	long	i;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	int		it_max;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	double	n1;
	double	n2;
	int		basex;
	int		basey;
	double	multi;
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

void					bird_init(t_fractal *f);
void					ft_bird(t_fractal *f);
void					celtic_init(t_fractal *f);
void					ft_celtic(t_fractal *f);
void					juliux_init(t_fractal *f);
void					ft_juliux(t_fractal *f);
void					text(t_env *e);
void					set(t_env *e);
int						quit(t_env *e);
void					cross(t_env *e);
void					reset(t_env *e);
void					hooks(t_env *e);
void					redraw(t_env *e);
void					tg_text(t_env *e);
void					usage(int error);
void					stop_mov(t_env *e);
void					init_img(t_env *e);
void					tg_it_zoom(t_env *e);
void					color_1(t_fractal *f);
void					color_2(t_fractal *f);
void					color_7(t_fractal *f);
void					color_8(t_fractal *f);
void					color_9(t_fractal *f);
int						expose_hook(t_env *e);
void					ft_burn(t_fractal *f);
void					change_color(t_env *e);
void					ft_julia(t_fractal *f);
void					init_point(t_point *p);
void					burn_init(t_fractal *f);
void					ft_newton(t_fractal *f);
void					julia_init(t_fractal *j);
void					multi_init(t_fractal *f);
int						init(t_env *e, char *arg);
void					mandel_init(t_fractal *f);
void					color_point(t_fractal *f);
void					newton_init(t_fractal *f);
void					ft_multibrot(t_fractal *f);
void					iter(int keycode, t_env *e);
void					move(int keycode, t_env *e);
void					ft_mandelbrot(t_fractal *f);
int						sinwave(t_col *c, double i);
int						choice(char *arg, t_env *e);
void					change(int keycode, t_env *e);
int						mmove(int x, int y, t_env *e);
void					key_zoom(int keycode, t_env *e);
int						key_hook(int keycode, t_env *e);
void					mov_phaze(int keycode, t_env *e);
int						drag(int button, int x, int y, t_env *e);
int						drop(int button, int x, int y, t_env *e);
void					put_pixel(int x, int y, int color, t_env *e);
void					zoom(t_env *e, int x, int y, double ratio);
void					draw(t_env *e, void (*fractal)(t_fractal *f));
int						mouse_hook(int button, int x, int y, t_env *e);
int						rgb2int(unsigned char r, unsigned char g,
						unsigned char b);
int						mlx_hook(void *win_ptr, int x_event, int x_mask,
						int (*funct)(), void *param);

#endif
