/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 20:45:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/31 22:04:49 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "libmlx/mlx.h"

static int			fdf_keys(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	else if (keycode == 126)
		fdf->obj.pos.y -= DY;
	else if (keycode == 125)
		fdf->obj.pos.y += DY;
	else if (keycode == 124)
		fdf->obj.pos.x += DX;
	else if (keycode == 123)
		fdf->obj.pos.x -= DX;
	if (keycode >= 123 && keycode <= 126)
		fdf->exp = 1;
	return (1);
}

void			fdf_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, WIN_NAME);
	obj_main_init(fdf);
	obj_main_display(fdf);
	fdf->exp = 1;
	mlx_key_hook(fdf->win, &fdf_keys, fdf);
	mlx_loop_hook(fdf->mlx, &fdf_loop, fdf);
	mlx_loop(fdf->mlx);
}
