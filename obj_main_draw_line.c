/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/07 13:23:05 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void			obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;

	dx = ABS(DX);
	sx = a.x < b.x ? 1 : -1;
	dy = ABS(DY);
	sy = a.y < b.y ? 1 : -1; 
	err = (dx > dy ? dx : -dy) / 2;
	while (!(a.x == b.x && a.y == b.y) && PIX(a))
	{
		e2 = err;
		if (e2 > - dx && ((err -= dy) || 1))
			a.x += sx;
		if (e2 < dy && ((err += dx) || 1))
			a.y += sy;
	}
}
