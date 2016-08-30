/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 16:07:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 14:08:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "libvect/libvect.h"
# define VECT_EXIT_FUNCTION	fdf_exit()
# define WIN_X		1000
# define WIN_Y		1000
# define WIN_NAME	"fdf"
# define DX			30
# define DY			30

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_fdf
{
	size_t			x;
	size_t			y;
	t_vect			*map;
	void			*mlx;
	void			*win;
	int				exp;
	void			*obj;
	t_coord			obj_coords;
}					t_fdf;

int					fdf_loop(t_fdf *fdf);
void				*obj_grid(t_coord a, t_coord b, t_coord d, t_fdf *fdf);
void				fdf_exit(void);
void				fdf_init(t_fdf *fdf);
void				map_draw(t_fdf *fdf);
void				map_parse(int fd, t_fdf *fdf);
void				obj_display(t_fdf *fdf);
void				obj_init(t_fdf *fdf);
void				x_draw_line(t_coord a, t_coord b, t_fdf *fdf);

#endif
