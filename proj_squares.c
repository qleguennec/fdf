/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_squares.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:23:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 15:14:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libvect/libvect.h"
#include <limits.h>
#include <math.h>

static void		color_factor(t_fdf *fdf, size_t size)
{
	long			z;
	int				factor;
	t_square		*sq;

	factor = 0;
	sq = fdf->squares->data;
	z = LONG_MIN;
	while (size)
	{
		if (z != sq[size].z_max)
		{
			z = sq[size].z_max;
			factor++;
		}
		size--;
	}
	fdf->color_decr = factor
		? (0xffffff - 0xF5A9A9) / factor
		: 0;
	printf("color decr: %x\n", fdf->color_decr);
}

static void		fill
	(t_v3 *v3, t_square *sq, size_t i, size_t offs)
{
	sq->a.x = ceil(v3[i].x);
	sq->a.y = ceil(v3[i].y);
	sq->b.x = ceil(v3[i + 1].x);
	sq->b.y = ceil(v3[i + 1].y);
	sq->c.x = ceil(v3[i + 1 + offs].x);
	sq->c.y = ceil(v3[i + 1 + offs].y);
	sq->d.x = ceil(v3[i + offs].x);
	sq->d.y = ceil(v3[i + offs].y);
	sq->z_max = ceil(v3[i].z);
	sq->z_max = MAX(sq->z_max, ceil(v3[i + 1].z));
	sq->z_max = MAX(sq->z_max, ceil(v3[i + offs].z));
	sq->z_max = MAX(sq->z_max, ceil(v3[i + offs + 1].z));
}

void			proj_squares(t_fdf *fdf)
{
	size_t			i;
	t_v3			*v3;
	t_square		sq;
	size_t			size;

	i = 0;
	size = fdf->proj->used / sizeof(*v3);
	v3 = fdf->proj->data;
	while (i < size)
	{
		if ((i + 1) % fdf->x && (i + 1 + fdf->x) < size)
		{
			fill(v3, &sq, i, fdf->x);
			vect_add(fdf->squares, &sq, sizeof(sq));
		}
		i++;
	}
	sort_quicksort(fdf->squares->data, fdf->squares->used / sizeof(sq));
	color_factor(fdf, size);
}
