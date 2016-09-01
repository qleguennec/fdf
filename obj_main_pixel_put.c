/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:44:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 13:40:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void			obj_main_pixel_put(t_v2 v2, t_fdf *fdf, unsigned int color)
{
	void		*null;

	null = 0;
//	if (!(v2.x >= 0 && v2.x < fdf->obj->size.x))
//	{
//		printf("canevas size: (%d, %d), pixel coords: (%d, %d)\n",
//			fdf->obj->size.x, fdf->obj->size.y, v2.x, v2.y);
//		(*((int *)null))++;
//	}
//	if (!(v2.y >= 0 && v2.y < fdf->obj->size.y))
//	{
//		printf("canevas size: (%d, %d), pixel coords: (%d, %d)\n",
//			fdf->obj->size.x, fdf->obj->size.y, v2.x, v2.y);
//		(*((int *)null))++;
//	}
	fdf->obj->data[fdf->obj->size.x * v2.y + v2.x] = color;
}
