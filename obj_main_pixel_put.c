/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:44:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 18:22:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

int				obj_main_pixel_put(t_v2 v2, t_fdf *fdf, unsigned int color)
{
	fdf->obj->data[fdf->obj->size.x * v2.y + v2.x] = color;
	return (1);
}
