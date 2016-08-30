/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:34:45 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 21:33:23 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void		obj_main_display(t_fdf *fdf)
{
	mlx_put_image_to_window(
		fdf->mlx
		, fdf->win
		, fdf->obj.img
		, fdf->obj.pos.x
		, fdf->obj.pos.y
	);
}
