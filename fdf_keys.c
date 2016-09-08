/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 10:18:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 17:54:28 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

int			fdf_keys(int keycode, t_fdf *fdf)
{
	static int		dx = 30;
	static int		dy = 30;
	static double	dec = 0.1;

	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	else if (keycode == 126)
		fdf->obj->pos.y -= dy;
	else if (keycode == 125)
		fdf->obj->pos.y += dy;
	else if (keycode == 124)
		fdf->obj->pos.x += dx;
	else if (keycode == 123)
		fdf->obj->pos.x -= dx;
	else
		return (1);
	fdf->exp = 1;
	return (1);
}
