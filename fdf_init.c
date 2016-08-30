/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 20:45:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 23:38:17 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/mlx.h"
#include "fdf.h"

static int			fdf_keys(int keycode, t_fdf *fdf)
{
	printf("%d\n", keycode);
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
	t_obj		main;

	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fdf_exit();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, WIN_NAME);
	obj_init(&main, 100, 100, fdf);
	fdf->obj = main;
	map_draw(fdf);
	obj_main_display(fdf);
	if (!fdf->win)
		fdf_exit();
	mlx_key_hook(fdf->win, &fdf_keys, fdf);
	mlx_loop_hook(fdf->mlx, &fdf_loop, fdf);
	mlx_loop(fdf->mlx);
}
