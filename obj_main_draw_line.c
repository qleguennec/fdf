/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 14:37:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void			obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	int e;
	int dx;
	int dy;

	e = b.x - a.x;
	dx = DX;
	dy = DY;
	while (a.x <= b.x)
	{
		obj_main_pixel_put(a, fdf, color);
		if ((e -= dy) <= 0 && ++a.y)
			e += dx;
		a.x++;
	}
}
