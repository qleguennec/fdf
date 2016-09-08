/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 18:00:46 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void			obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	t_v2	d;
	t_v2	s;
	int		err;
	int		e2;

	d.x = ABS(DX);
	s.x = a.x < b.x ? 1 : -1;
	d.y = ABS(DY);
	s.y = a.y < b.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (!(a.x == b.x && a.y == b.y) && PIX(a))
	{
		e2 = err;
		if (e2 > -d.x && ((err -= d.y) || 1))
			a.x += s.x;
		if (e2 < d.y && ((err += d.x) || 1))
			a.y += s.y;
	}
}
