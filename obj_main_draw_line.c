/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 20:25:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void			obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			dp;
	int			de;
	int			dne;

	x = a.x;
	y = a.y;
	dx = b.x - a.x;
	dy = b.y - a.y;
	dp = 2 * dy - dx;
	de = 2 * dy;
	dne = 2 * (dy - dx);
	obj_main_pixel_put(x, y, fdf, color);
	while (x < b.x)
	{
		dp += dp <= 0 ? de : dne;
		y += dp <= 0 ? 0 : 1;
		obj_main_pixel_put(++x, y, fdf, color);
	}
}
