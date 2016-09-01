/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_compute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 23:48:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 19:28:33 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"

static t_v2			map_v3_v2(t_v3 v3, t_v2 offs, t_v2 *min)
{
	t_v2			v2;

	v2.x = nearbyint(v3.x * SX);
	v2.y = nearbyint(v3.z * SZ);
	v2.x += offs.x;
	v2.y += offs.y;
	min->x = MIN(min->x, v2.x);
	min->y = MIN(min->y, v2.y);
	return (v2);
}

static void			step(int is_x, t_v3 *v3, t_v2 *offs)
{
	if (is_x)
	{
		v3->x++;
		offs->x += IMG_DX;
	}
	else
	{
		v3->y++;
		offs->y += IMG_DY;
		offs->x = 0;
		v3->x = 0;
	}
}

t_v2				translate(t_v2 min, t_fdf *fdf)
{
	size_t	i;
	t_v2	*v2;
	t_v2	max;

	i = 0;
	max.x = -((int)-1) - 1;
	max.y = -((int)-1) - 1;
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
	min.x = (int)-1;
	min.y = (int)-1;
	while (i < fdf->map->used)
	{
		v3.z = *((int *)(fdf->map->data + i));
		v3 = v3_transform(v3, fdf);
		v2 = map_v3_v2(v3, offs, &min);
		vect_add(fdf->proj, &v2, sizeof(v2));
		step(!(v3.x == (int)fdf->x - 1), &v3, &offs);
		i += 4;
	}
	return (translate(min, fdf));
}
