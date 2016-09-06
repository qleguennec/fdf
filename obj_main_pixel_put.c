/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:44:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/06 18:00:53 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

int				obj_main_pixel_put(t_v2 v2, t_fdf *fdf, unsigned int color)
{
	int			*null;

	null = 0;
	if (!(v2.x >= 0 && v2.x < fdf->obj->size.x) || 
		!(v2.y >= 0 && v2.y < fdf->obj->size.y))
		*null++;
	fdf->obj->data[fdf->obj->size.x * v2.y + v2.x] = color;
	return (1);
}
