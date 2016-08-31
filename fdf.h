/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 16:07:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/31 21:42:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <assert.h>
# include "libvect/libvect.h"
# define VECT_EXIT_FUNCTION	fdf_exit()
# define WIN_X		1000
# define WIN_Y		1000
# define WIN_NAME	"fdf"
# define DX			30
# define DY			30
# define DD			30
# define SX			0.75
# define SZ			0.3
# define BASE_COL	0x00FF
# define ROT		M_PI_2

typedef struct		s_v2
{
	int				x;
	int				y;
}					t_v2;

typedef struct		s_v3
{
	int				x;
	int				y;
	int				z;
}					t_v3;

typedef struct		s_obj
{
	void			*img;
	int				*data;
	t_v2			size;
	t_v2			pos;
}					t_obj;

typedef struct		s_fdf
{
	size_t			x;
	size_t			y;
	t_vect			*map;
	t_vect			*proj;
	void			*mlx;
	void			*win;
	int				exp;
	t_obj			obj;
}					t_fdf;

int					fdf_loop(t_fdf *fdf);
void				fdf_exit(void);
void				fdf_init(t_fdf *fdf);
void				obj_main_init(t_fdf *fdf);
t_v2				proj_compute(t_fdf *fdf);
void				map_parse(int fd, t_fdf *fdf);
void				obj_main_display(t_fdf *fdf);
void				obj_main_pixel_put(t_v2 a, t_fdf *fdf, unsigned int color);
void				obj_main_draw_line(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color);
void				obj_init(t_obj *obj, int w, int h, t_fdf *fdf);
void				obj_main_frame(t_fdf *fdf); //debug
t_v2				v2_add(t_v2 a, t_v2 b);
t_v2				v2_transform(t_v2 a, int n);
t_v2				v2_abs(t_v2 a);

#endif
