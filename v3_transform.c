/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:09:44 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 19:24:05 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_v3	v3_rotate(t_v3 v3, t_fdf *fdf)
{
	t_v3	v3_r;

	//v3_r = mat_apply(v3, fdf->rot_mat_zeta);
	//v3_r = mat_apply(v3_r, fdf->rot_mat_gamma);
	v3_r = mat_apply(v3, fdf->rot_mat_alpha);
	return (v3_r);
}

t_v3		v3_transform(t_v3 v3, t_fdf *fdf)
{
	return (v3_rotate(v3, fdf));
}
