/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:09:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/31 22:04:44 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

int				fdf_loop(t_fdf *fdf)
{
	if (!fdf->exp)
		return (1);
	obj_main_display(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->obj.img
		, fdf->obj.pos.x
		, fdf->obj.pos.y);
	fdf->exp = 0;
	return (0);
}
