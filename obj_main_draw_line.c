/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/06 17:51:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

static void		bresen_y
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	int			d;
	t_v2		dd;
	t_v2		inc;
	int			xinc;

	if (a.y > b.y)
		return (bresen_y(b, a, fdf, color));
	xinc = b.x > a.x ? 1 : -1;
	dd.y = DY;
	dd.x = ABS(DX);
	d = 2 * dd.x - dd.y;
	inc.x = 2 * (dd.x - dd.y);
	inc.y = 2 * dd.x;
	while (a.y < b.y && PIX(a))
	{
		if (d > 0)
			a.x += xinc;
		d += d > 0 ? inc.x : inc.y;
		a.y++;
	}
}

static void		bresen_x
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	int			d;
	t_v2		dd;
	t_v2		inc;
	int			yinc;

	if (a.x > b.x)
		return (bresen_x(b, a, fdf, color));
	yinc = b.y > a.y ? 1 : -1;
	dd.x = DX;
	dd.y = ABS(DY);
	d = 2 * dd.y - dd.x;
	inc.x = 2 * (dd.y - dd.x);
	inc.y = 2 * dd.y;
	while (a.x < b.x && PIX(a))
	{
		if (d > 0)
			a.y += yinc;
		d += d > 0 ? inc.x : inc.y;
		a.x++;
	}
}

void			obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	if (DX < DY)
		bresen_y(a, b, fdf, color);
	else
		bresen_x(a, b, fdf, color);
}
