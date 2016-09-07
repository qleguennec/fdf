/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_compute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 23:48:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/07 11:31:03 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <limits.h>
#include "fdf.h"

static t_v2			map_v3_v2(t_v3 v3, t_v2 offs, t_v2 *min)
{
	t_v2			v2;
	t_v3			tmp;
	t_v3			iso;
	static double	sx = 1;
	static double	sy = - 1;
	static double	sz = 0.3;
	static double	a = 35.264;
	static double	b = 45;

	v3.x *= sx;
	v3.y *= sy;
	v3.z *= sz;
	tmp.x = cos(b) * v3.x - sin(b) * v3.z;
	tmp.y = v3.y;
	tmp.z = sin(b) * v3.x + cos(b) * v3.z;
	iso.x = tmp.x;
	iso.y = cos(a) * tmp.y + sin(a) * tmp.z;
	iso.z = cos(a) * tmp.z - sin(a) * tmp.y;
	v2.x = nearbyint((iso.x + offs.x) * 20);
	v2.y = nearbyint((iso.y + offs.y) * 20);
	min->x = MIN(min->x, v2.x);
	min->y = MIN(min->y, v2.y);
	return (v2);
}

static void			step(int is_x, t_v3 *v3, t_v2 *offs)
{
	static t_v2		dd = {1, 1};

	if (is_x)
	{
		v3->x++;
		offs->x += dd.x;
		return ;
	}
	v3->y++;
	offs->y += dd.y;
	offs->x = 0;
	v3->x = 0;
}

t_v2				translate(t_v2 min, t_fdf *fdf)
{
	size_t	i;
	t_v2	*v2;
	t_v2	max;

	i = 0;
	max.x = INT_MIN;
	max.y = INT_MIN;
	v2 = fdf->proj->data;
	min = v2_abs(min);
	while (i < fdf->proj->used / sizeof(t_v2))
	{
		v2[i] = v2_add(v2[i], min);
		max.x = MAX(max.x, v2[i].x);
		max.y = MAX(max.y, v2[i].y);
		i++;
	}
	max.x++;
	max.y++;
	return (max);
}

t_v2				proj_compute(t_fdf *fdf)
{
	t_v3	v3;
	t_v2	v2;
	t_v2	min;
	t_v2	offs;
	size_t	i;

	i = 0;
	ft_bzero(&v3, sizeof(v3));
	ft_bzero(&offs, sizeof(offs));
	min.x = INT_MAX;
	min.y = INT_MAX;
	while (i < fdf->map->used)
	{
		v3.z = *((int *)(fdf->map->data + i));
		v2 = map_v3_v2(v3, offs, &min);
		vect_add(fdf->proj, &v2, sizeof(v2));
		step(!(v3.x == (int)fdf->x - 1), &v3, &offs);
		i += 4;
	}
	return (translate(min, fdf));
}
