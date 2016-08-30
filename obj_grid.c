/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 09:54:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 13:54:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "libmlx/mlx.h"
#include <limits.h>

void			*obj_grid(t_coord a, t_coord b, t_coord d, t_fdf *fdf)
{
	void	*obj;
	int		*obj_data;
	int		i;
	int		j;
	int		sl;

	obj = mlx_new_image(fdf->mlx, b.x - a.x, b.y - a.y);
	obj_data = (int *)mlx_get_data_addr(obj, &j, &sl, &j);
	j = 0;
	sl /= 4;
	while (j < b.y - a.y)
	{
		i = 0;
		while (i < sl)
			(obj_data + j * sl)[i++] = 0xFFFF;
		j += d.y;
	}
	i = 0;
	while (i < sl)
	{
		j = 0;
		while (j < b.y - a.y)
			(obj_data + j++ * sl)[i] = 0xFFFFFF;
		i += d.x;
	}
	return (obj);
}
