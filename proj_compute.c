/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_compute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 23:48:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/07 21:14:32 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <limits.h>
#include "fdf.h"

static t_v3			map_v3(t_v3 v3, t_v2 offs, t_v2 *min)
{
	t_v3			point3;
	t_v3			tmp;
	t_v3			iso;
	static double	sx = 1;
	static double	sy = - 1;
	static double	sz = 0.2;
	static double	a = 35.264;
	static double	b = 45;

	v3.x *= sx;
	v3.y *= sy;
	v3.z *= sz;
	point3.z = v3.z;
	tmp.x = cos(b) * v3.x - sin(b) * v3.z;
	tmp.y = v3.y;
	tmp.z = sin(b) * v3.x + cos(b) * v3.z;
	iso.x = tmp.x;
	iso.y = cos(a) * tmp.y + sin(a) * tmp.z;
	iso.z = cos(a) * tmp.z - sin(a) * tmp.y;
	point3.x = nearbyint((iso.x + offs.x) * 20);
	point3.y = nearbyint((iso.y + offs.y) * 20);
	min->x = MIN(min->x, point3.x);
	min->y = MIN(min->y, point3.y);
	return (point3);
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
	t_v3	*v3;
	t_v2	max;

	i = 0;
	max.x = INT_MIN;
	max.y = INT_MIN;
	v3 = fdf->proj->data;
	min = v2_abs(min);
	while (i < fdf->proj->used / sizeof(*v3))
	{
		v3[i].x += min.x;
		v3[i].y += min.y;
		max.x = MAX(max.x, v3[i].x);
		max.y = MAX(max.y, v3[i].y);
		i++;
	}
	max.x++;
	max.y++;
	return (max);
}

t_v2				proj_compute(t_fdf *fdf)
{
	t_v3	v3;
	t_v3	point3;
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
		point3 = map_v3(v3, offs, &min);
		vect_add(fdf->proj, &point3, sizeof(point3));
		step(!(v3.x == (int)fdf->x - 1), &v3, &offs);
		i += 4;
	}
	return (translate(min, fdf));
}
