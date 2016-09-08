/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:26:36 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 17:01:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_v2		obj_main_scale(t_v3 sf, t_fdf *fdf)
{
	t_v3			*v3;
	t_v3			max;
	size_t			i;

	i = 0;
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
