/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 23:48:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/29 23:56:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void			map_draw(t_fdf *fdf)
{
	int			x;
	int			y;

	y = DY * fdf->y;
	while (y > (int)fdf->y)
	{
		x = DX * fdf->x;
		while (x > (int)fdf->x)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFF);
			x -= DX;
		}
		y -= DY;
	}
}
