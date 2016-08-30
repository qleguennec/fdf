/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 20:28:44 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 21:20:32 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmlx/mlx.h"
#include "libft/libft.h"

void			obj_init(t_obj *obj, int w, int h, t_fdf *fdf)
{
	int			dummy;

	ft_bzero(obj, sizeof(*obj));
	obj->img = mlx_new_image(fdf->mlx, w, h);
	obj->data = (int *)mlx_get_data_addr(obj->img, &dummy, &dummy, &dummy);
	obj->size.x = w;
	obj->size.y = h;
}