/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:44:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/31 22:05:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void			obj_main_pixel_put(t_v2 v2, t_fdf *fdf, unsigned int color)
{
	assert(v2.x >= 0 && v2.x < fdf->obj.size.x);
	assert(v2.y >= 0 && v2.y < fdf->obj.size.y);
	printf("(%d)\n", fdf->obj.size.x * v2.y + v2.x);
	fdf->obj.data[fdf->obj.size.x * v2.y + v2.x] = color;
}
