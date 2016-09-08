/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:34:45 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 18:06:27 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

static void	draw_points(t_fdf *fdf, unsigned int color)
{
	size_t	i;
	t_v3	*v3;
	t_v2	v2;

	i = 0;
	v3 = fdf->proj->data;
	while (i < fdf->proj->used / sizeof(*v3))
	{
		v2.x = v3[i].x;
		v2.y = v3[i].y;
		obj_main_pixel_put(v2, fdf, color);
		i++;
	}
}

static void	draw_squares(t_fdf *fdf)
{
	size_t					i;
	t_square				*sq;
	static unsigned int		base_col = 0xF5A9A9;
	long					z;

	i = 0;
	sq = fdf->squares->data;
	z = sq->z_max;
	while (i < fdf->squares->used / sizeof(*sq))
	{
		if (sq[i].z_max != z)
		{
			base_col -= fdf->color_decr;
			z = sq[i].z_max;
		}
		obj_main_draw_line(sq[i].a, sq[i].b, fdf, base_col);
		obj_main_draw_line(sq[i].b, sq[i].c, fdf, base_col);
		obj_main_draw_line(sq[i].c, sq[i].d, fdf, base_col);
		obj_main_draw_line(sq[i].d, sq[i].a, fdf, base_col);
		i++;
	}
}

void		obj_main_display(t_fdf *fdf)
{
	draw_squares(fdf);
}
