/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_draw_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:55:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/29 23:47:11 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void			x_draw_line(t_coord a, t_coord b, t_fdf *fdf)
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			dp;
	int			de;
	int			dne;

	x = a.x;
	y = a.y;
	dx = b.x - a.x;
	dy = b.y - a.y;
	dp = 2 * dy - dx;
	de = 2 * dy;
	dne = 2 * (dy - dx);
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
	while (x < b.x)
	{
		dp += dp <= 0 ? de : dne;
		y += dp <= 0 ? 0 : 1;
		x++;
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
	}
}
