/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:44:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 21:28:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void			obj_main_pixel_put
	(int x, int y, t_fdf *fdf, unsigned int color)
{
	assert(x >= 0 && x <= fdf->obj.size.x);
	assert(y >= 0 && y <= fdf->obj.size.y);
	fdf->obj.data[fdf->obj.size.x * y + x] = color;
}
