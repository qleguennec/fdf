/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:09:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/07 22:34:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

static void		display_coords(t_fdf *fdf)
{
	char		buffer[1024];

	ft_bzero(buffer, sizeof(buffer));
	snprintf(buffer, 1024, "> img size: (%d, %d) > win size: (%d, %d)"
		, fdf->obj->size.x, fdf->obj->size.y, WIN_X, WIN_Y);
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, 0xffffff, buffer);
}

int				fdf_loop(t_fdf *fdf)
{
	if (!fdf->exp)
		return (1);
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->obj->img
		, fdf->obj->pos.x
		, fdf->obj->pos.y);
	display_coords(fdf);
	fdf->exp = 0;
	return (0);
}
