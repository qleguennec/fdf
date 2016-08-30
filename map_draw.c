/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 23:48:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/31 00:06:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static t_v2		map_v3_v2(int x, int y, int z)
{
	t_v2		ret;

	ret.x = x * SX;
	ret.y = z * SZ;
	y = 0;
	return (ret);
}

void			map_draw(t_fdf *fdf)
{
	int		x;
	int		y;
	t_v2	v2;
	size_t	i;

	i = 0;
	x = 0;
	y = 0;
	printf("used: %lu\n", fdf->map->used);
	while (i < fdf->map->used)
	{
		printf("x=%d, y=%d, z=%d\n", x, y, ((int *)fdf->map->data)[i]);
		v2 = map_v3_v2(x, y, *((int *)fdf->map->data + i));
		obj_main_pixel_put(v2.x, v2.y, fdf, 0xff00);
		x = i && !(i % fdf->x) && ++y ? 0 : x + 1;
		i += 4;
	}
}
