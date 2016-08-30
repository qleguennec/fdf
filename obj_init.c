/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:29:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 14:08:09 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

void		obj_init(t_fdf *fdf)
{
	t_coord	a;
	t_coord	b;
	t_coord d;

	a.x = 0;
	a.y = 0;
	b.x = 500;
	b.y = 500;
	d.x = 50;
	d.y = 50;
	fdf->obj = obj_grid(a, b, d, fdf);
}
