/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 10:18:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 10:20:39 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

int			fdf_keys(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	else if (keycode == 126)
		fdf->obj->pos.y -= IMG_DY;
	else if (keycode == 125)
		fdf->obj->pos.y += IMG_DY;
	else if (keycode == 124)
		fdf->obj->pos.x += IMG_DX;
	else if (keycode == 123)
		fdf->obj->pos.x -= IMG_DX;
	if (keycode >= 123 && keycode <= 126)
		fdf->exp = 1;
	return (1);
}
