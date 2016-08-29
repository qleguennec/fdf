/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 20:45:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/29 21:52:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"

int				fdf_keys(int keycode, void *param)
{
	t_fdf		*fdf;

	fdf = param;
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (0);
}

void			fdf_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fdf_exit();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, WIN_NAME);
	if (!fdf->win)
		fdf_exit();
	mlx_key_hook(fdf->win, &fdf_keys, fdf);
	mlx_loop(fdf->mlx);
}
