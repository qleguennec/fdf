/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:09:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 21:34:11 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

int				fdf_loop(t_fdf *fdf)
{
	if (fdf->exp)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		obj_main_display(fdf);
		fdf->exp = 0;
	}
	return (1);
}
