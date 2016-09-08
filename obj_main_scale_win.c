/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_scale_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:46:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 18:13:29 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static t_v3		scale_factor(t_v3 max)
{
	t_v3			sf;
	static double	incr = 0.2;
	static double	wf = 1.5;

	sf.x = 1;
	sf.y = 1;
	while (floor(max.x * sf.x) < WIN_X / wf)
		sf.x += incr;
	while (floor(max.y * sf.y) < WIN_Y / wf)
		sf.y += incr;
	while (sf.x > 0 && floor(max.x * sf.x) > WIN_X / wf)
		sf.x -= incr;
	while (sf.y > 0 && floor(max.y * sf.y) > WIN_Y / wf)
		sf.y -= incr;
	return (sf);
}

t_v2			obj_main_scale_win(t_fdf *fdf)
{
	t_v3		max;

	max.x = fdf->obj->size.x;
	max.y = fdf->obj->size.y;
	fdf->obj->sf = scale_factor(max);
	return (obj_main_scale(fdf->obj->sf, fdf));
}
