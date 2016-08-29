/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 16:07:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/29 21:36:14 by qle-guen         ###   ########.fr       */
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

typedef struct		s_fdf
{
	size_t			x;
	size_t			y;
	t_vect			*map;
	void			*mlx;
	void			*win;
}					t_fdf;

void				map_parse(int fd, t_fdf *fdf);
void				fdf_exit(void);
void				fdf_init(t_fdf *fdf);

#endif
