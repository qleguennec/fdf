/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:34:45 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/06 14:16:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"

static void	draw_points(t_fdf *fdf, unsigned int color)
{
	size_t	i;
	t_v2	*v2;

	i = 0;
	v2 = fdf->proj->data;
	while (i < fdf->proj->used / sizeof(v2))
	{
		obj_main_pixel_put(v2[i], fdf, color);
		i++;
	}
}

static void	draw_map(t_fdf *fdf, unsigned int color)
{
	size_t	i;
	t_v2	*v2;

	i = 0;
	v2 = fdf->proj->data;
	while (i < fdf->proj->used / sizeof(*v2))
	{
		if ((i + 1) % fdf->x)
			obj_main_draw_line(v2[i], v2[i + 1], fdf, color);
		if ((i + fdf->x) != fdf->y)
			obj_main_draw_line(v2[i], v2[i + fdf->x], fdf, color);
		i++;
	}
}

static void	draw_frame(t_fdf *fdf, unsigned int color)
{
	t_v2	v2;
	t_v2	a;
	t_v2	b;
	t_v2	c;
	t_v2	d;

	ft_bzero(&v2, sizeof(v2));
	a.x = 0;
	a.y = 0;
	b.x = fdf->obj->size.x;
	b.y = 0;
	c.x = fdf->obj->size.x;
	c.y = fdf->obj->size.y;
	d.x = 0;
	d.y = fdf->obj->size.y;
	obj_main_draw_line(a, b, fdf, color);
	obj_main_draw_line(c, b, fdf, color);
	obj_main_draw_line(d, c, fdf, color);
	obj_main_draw_line(a, d, fdf, color);
//	while (v2.x < fdf->obj->size.x)
//	{
//		obj_main_pixel_put(v2, fdf, color);
//		v2.x++;
//	}
//	v2.x--;
//	while (v2.y < fdf->obj->size.y)
//	{
//		obj_main_pixel_put(v2, fdf, color);
//		v2.y++;
//	}
//	v2.y--;
//	while (v2.x >= 0)
//	{
//		obj_main_pixel_put(v2, fdf, color);
//		v2.x--;
//	}
//	v2.x++;
//	while (v2.y >= 0)
//	{
//		obj_main_pixel_put(v2, fdf, color);
//		v2.y--;
//	}
//	v2.x++;
}

void		obj_main_display(t_fdf *fdf)
{
	draw_map(fdf, 0xffffff);
	draw_points(fdf, 0xff0000);
	return ;
}
