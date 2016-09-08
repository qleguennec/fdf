/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 16:07:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 18:13:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <assert.h>
# include "libft/libft.h"
# include "libvect/libvect.h"
# define VECT_EXIT_FUNCTION	fdf_exit()
# define WIN_X		800
# define WIN_Y		800
# define SX			1
# define SY			- 1
# define SZ			0.2
# define A_DEG		35.264
# define B_DEG		45
# define WIN_NAME	"fdf"
# define BASE_COL	0x00FF
# define ROT		M_PI_2

# define PIX(p)		obj_main_pixel_put(a, fdf, color)
# define DX			(b.x - a.x)
# define DY			(b.y - a.y)

typedef struct		s_v2
{
	int				x;
	int				y;
}					t_v2;

typedef struct		s_v3
{
	double			x;
	double			y;
	double			z;
}					t_v3;

typedef struct		s_square
{
	t_v2			a;
	t_v2			b;
	t_v2			c;
	t_v2			d;
	int				z_max;
}					t_square;

typedef struct		s_obj
{
	void			*img;
	int				*data;
	t_v2			size;
	t_v2			pos;
	t_v3			sf;
}					t_obj;

typedef struct		s_fdf
{
	size_t			x;
	size_t			y;
	t_vect			*map;
	t_vect			*proj;
	t_vect			*squares;
	void			*mlx;
	void			*win;
	unsigned int	exp : 1;
	t_obj			*obj;
	unsigned int	color_decr;
	double			sz;
}					t_fdf;

int					fdf_keys(int keycode, t_fdf *fdf);
int					fdf_loop(t_fdf *fdf);
int					obj_main_pixel_put(t_v2 a, t_fdf *fdf, unsigned int color);
t_v2				obj_main_scale(t_v3 sf, t_fdf *fdf);
t_v2				obj_main_scale_win(t_fdf *fdf);
t_v2				proj_compute(t_fdf *fdf);
t_v2				v2_abs(t_v2 a);
t_v2				v2_add(t_v2 a, t_v2 b);
t_v2				v2_scale(t_v2 a, double n);
t_v3				v3_transform(t_v3 v3, t_fdf *fdf);
void				fdf_exit(void);
void				fdf_init(t_fdf *fdf);
void				map_parse(int fd, t_fdf *fdf);
void				obj_init(t_obj *obj, int w, int h, t_fdf *fdf);
void				obj_main_display(t_fdf *fdf);
void				obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color);
void				obj_main_frame(t_fdf *fdf);
void				obj_main_init(t_fdf *fdf);
void				proj_squares(t_fdf *fdf);
void				sort_quicksort(t_square *sq, size_t n);

#endif
