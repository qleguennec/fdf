/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 18:22:52 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 18:42:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void		obj_main_init(t_fdf *fdf)
{
	int		dummy;

	fdf->obj->size = proj_compute(fdf);
	fdf->obj->size = obj_main_scale_win(fdf);
	fdf->obj->size.x++;
	fdf->obj->size.y++;
	if (fdf->y > 1)
		proj_squares(fdf);
	fdf->obj->img = mlx_new_image(fdf->mlx
		, fdf->obj->size.x, fdf->obj->size.y);
	if (!fdf->obj->img)
		fdf_exit();
	fdf->obj->data = (int *)mlx_get_data_addr(fdf->obj->img
		, &dummy, &dummy, &dummy);
	fdf->obj->pos.x = WIN_X / 2 - fdf->obj->size.x / 2;
	fdf->obj->pos.y = WIN_Y / 2 - fdf->obj->size.y / 2;
}
