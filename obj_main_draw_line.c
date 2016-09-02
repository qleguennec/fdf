/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/03 00:59:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

static int		step
	(t_v2 dd, int *e)
{
	int			cond;
	int			sign;

	cond = dd.x < 0 && dd.y < 0
		? ABS(dd.x) <= ABS(dd.y)
		: ABS(dd.x) >= ABS(dd.y);
	sign = dd.x < 0 && dd.y < 0 ? -1 : 1;
	printf("e0=%d, e1=%d\n", *e, *e + 2 * (cond ? dd.y : dd.x));
	*e += 2 * (cond ? dd.y : dd.x);
	if (*e < 0)
	{
		*e += 2 * (cond ? dd.x : dd.y);
		return (1);
	}
	return (0);
}

static void		draw_sidelong
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	t_v2		dd;
	int			e;
	int			*inc1;
	int			*inc2;
	int			cmp;
	int			cond;

	dd.x = DX;
	dd.y = DY;
	cond = dd.x < 0 && dd.y < 0
		? ABS(dd.x) <= ABS(dd.y)
		: ABS(dd.x) >= ABS(dd.y);
	e = cond ? dd.x : dd.y;
	inc1 = cond ? &a.x : &a.y;
	inc2 = cond ? &a.y : &a.x;
	cmp = cond ? b.x : b.y;
	while (*inc1 < cmp && PIX(a))
	{
		printf("c = %d, e = %d, dd=(%d, %d) a=(%d, %d) b=(%d, %d) \n", cond, e, dd.x, dd.y, a.x, a.y, b.x, b.y);
		*inc1 += SIGN(cond ? dd.x : dd.y);
		*inc2 += SIGN(cond ? dd.y : dd.x) * step(dd, &e);
	}
}

void			obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	draw_sidelong(a, b, fdf, color);
}
