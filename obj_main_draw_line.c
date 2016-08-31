/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/31 19:06:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void			obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	t_v2		c;
	int			dx;
	int			dy;
	int			dp;
	int			de;
	int			dne;

	c.x = a.x;
	c.y = a.y;
	dx = b.x - a.x;
	dy = b.y - a.y;
	dp = 2 * dy - dx;
	de = 2 * dy;
	dne = 2 * (dy - dx);
	obj_main_pixel_put(c, fdf, color);
	while (c.x < b.x)
	{
		dp += dp <= 0 ? de : dne;
		c.y += dp <= 0 ? 0 : 1;
		c.x++;
		obj_main_pixel_put(c, fdf, color);
	}
}
