/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_main_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:34:45 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/31 22:29:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"
#include "libft/libft.h"


static void	draw_points(t_fdf *fdf)
{
	size_t	i;
	t_v2	*v2;

	i = 0;
	v2 = fdf->proj->data;
	while (i < fdf->proj->used / sizeof(v2))
		obj_main_pixel_put(v2[i++], fdf, 0xcc66ff);
}

static void	draw_map(t_fdf *fdf)
{
	size_t	i;
	t_v2	*v2;

	i = 0;
	v2 = fdf->proj->data;
	while (i < fdf->proj->used / sizeof(v2) - sizeof(v2))
	{
		obj_main_draw_line(v2[i], v2[i + 1], fdf, BASE_COL);
		i++;
		obj_main_draw_line(v2[i], v2[i + 1], fdf, BASE_COL);
	}
}

static void	draw_frame(t_fdf *fdf)
{
	t_v2	v2;

	ft_bzero(&v2, sizeof(v2));
	v2.y = 10;
	while (v2.x < fdf->obj.size.x)
	{
		obj_main_pixel_put(v2, fdf, BASE_COL);
		v2.x++;
	}
}

void		obj_main_display(t_fdf *fdf)
{
	draw_points(fdf);
	return ;
}
