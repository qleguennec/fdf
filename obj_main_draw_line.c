/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/04 20:06:44 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

static void		bresen1
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	t_v2		dd;
	int			e;

	dd.x = DX * 2;
	dd.y = DY * 2;
	if (dd.x >= dd.y)
	{
		e = DX;
		while (PIX(a) && ++a.x <= b.x)
		{
			if ((e -= dd.y) < 0 && ((e += dd.x) || 1))
				a.y++;
		}
	}
	else
	{
		e = DY;
		while (PIX(a) && ++a.y <= b.y)
		{
			if ((e -= dd.x) < 0 && ((e += dd.y) || 1))
				a.x++;
		}
	}
}

static void		bresen2
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	t_v2		dd;
	int			e;

	dd.x = DX * 2;
	dd.y = DY * 2;
	if (dd.x >= - dd.y)
	{
		e = DX;
		while (PIX(a) && ++a.x <= b.x)
		{
			if ((e += dd.y) <= 0 && ((e += dd.x) || 1))
				a.y--;
		}
	}
	else
	{
		e = DY;
		while (PIX(a) && --a.y <= b.y)
		{
			if ((e += dd.x) > 0 && ((e += dd.y) || 1))
				a.x++;
		}
	}
}

static void		bresen3
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	t_v2		dd;
	int			e;

	dd.x = DX * 2;
	dd.y = DY * 2;
	if (- dd.x >= dd.y)
	{
		e = DX;
		while (PIX(a) && --a.x <= b.x)
		{
			if ((e += dd.y) >= 0 && ((e += dd.x) || 1))
				a.y++;
		}
	}
	else
	{
		e = DY;
		while (PIX(a) && ++a.y <= b.y)
		{
			if ((e += dd.x) <= 0 && ((e += dd.y) || 1))
				a.x--;
		}
	}
}

static void		bresen4
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	t_v2		dd;
	int			e;

	dd.x = DX * 2;
	dd.y = DY * 2;
	if (dd.x <= dd.y)
	{
		e = DX;
		while (PIX(a) && --a.x <= b.x)
		{
			if ((e -= dd.y) >= 0 && ((e += dd.x) || 1))
				a.y--;
		}
	}
	else
	{
		e = DY;
		while (PIX(a) && --a.y <= b.y)
		{
			if ((e -= dd.x) >= 0 && ((e += dd.y) || 1))
				a.x--;
		}
	}
}

void			obj_main_draw_line
	(t_v2 a, t_v2 b, t_fdf *fdf, unsigned int color)
{
	if (DX > 0 && DY > 0)
		bresen1(a, b, fdf, color);
	else if (DX > 0)
		bresen2(a, b, fdf, color);
	else if (DX < 0 && DY > 0)
		bresen3(a, b, fdf, color);
	else
		bresen4(a, b, fdf, color);
}
