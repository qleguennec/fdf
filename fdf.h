/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 16:07:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 19:29:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <assert.h>
# include "libft/libft.h"
# include "libvect/libvect.h"
# define VECT_EXIT_FUNCTION	fdf_exit()
# define WIN_X		1000
# define WIN_Y		1000
# define WIN_NAME	"fdf"
# define DD			30
# define IMG_DX		30
# define IMG_DY		30
# define SX			0.5
# define SZ			0.5
# define BASE_COL	0x00FF
# define ROT		M_PI_2

# define DX			ABS(b.x - a.x)
# define DY			ABS(b.y - a.y)

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
	unsigned int	exp : 1;
	t_obj			*obj;
	double			rot_mat_alpha[9];
	double			rot_mat_gamma[9];
	double			rot_mat_zeta[9];
}					t_fdf;

int					fdf_keys(int keycode, t_fdf *fdf);
int					fdf_loop(t_fdf *fdf);
t_v2				proj_compute(t_fdf *fdf);
t_v2				v2_abs(t_v2 a);
t_v2				v2_add(t_v2 a, t_v2 b);
t_v2				v2_scale(t_v2 a, double n);
t_v3				mat_apply(t_v3 v3, double *mat);
t_v3				v3_transform(t_v3 v3, t_fdf *fdf);
void				fdf_exit(void);
void				fdf_init(t_fdf *fdf);
void				map_parse(int fd, t_fdf *fdf);
void				mat_rot_init(t_fdf *fdf);
void				obj_init(t_obj *obj, int w, int h, t_fdf *fdf);
void				obj_main_display(t_fdf *fdf);
void				obj_main_draw_line(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color);
void				obj_main_frame(t_fdf *fdf); //debug
void				obj_main_init(t_fdf *fdf);
void				obj_main_pixel_put(t_v2 a, t_fdf *fdf, unsigned int color);

#endif
