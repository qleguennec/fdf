/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_scale_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:46:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 16:02:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static t_v3		scale_factor(t_v3 max)
{
	t_v3			sf;
	static double	incr = 0.2;

	sf.x = 1;
	sf.y = 1;
	while (floor(max.x * sf.x) < WIN_X)
		sf.x += incr;
	while (floor(max.x * sf.y) < WIN_Y)
		sf.y += incr;
	while (sf.x > 0 && floor(max.x * sf.x) > WIN_X)
		sf.x -= incr;
	while (sf.y > 0 && floor(max.y * sf.y) > WIN_Y)
		sf.y -= incr;
	return (sf);
}

t_v2			obj_main_scale_win(t_fdf *fdf)
{
	t_v3			*v3;
	t_v3			max;
	t_v3			sf;
	size_t			i;

	i = 0;
	max.x = fdf->obj->size.x;
	max.y = fdf->obj->size.y;
	sf = scale_factor(max);
	v3 = fdf->proj->data;
	max.x = floor(v3[i].x * sf.x);
	max.y = floor(v3[i].y * sf.y);
	while (i < fdf->proj->used / sizeof(*v3))
	{
		v3[i].x = floor(v3[i].x * sf.x);
		v3[i].y = floor(v3[i].y * sf.y);
		max.x = MAX(max.x, v3[i].x);
		max.y = MAX(max.y, v3[i].y);
		i++;
	}
	return ((t_v2){ceil(max.x), ceil(max.y)});
}
