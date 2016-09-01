/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rot_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:18:46 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 19:35:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		mat_rot_init(t_fdf *fdf)
{
	static double	rotx = M_PI_4 / 2;
	static double	roty = M_PI_4;
	static double	rotz = 0;

	fdf->rot_mat_alpha[0] = 1;
	fdf->rot_mat_alpha[4] = cos(rotx);
	fdf->rot_mat_alpha[5] = - sin(rotx);
	fdf->rot_mat_alpha[7] = sin(rotx);
	fdf->rot_mat_alpha[8] = cos(rotx);
	fdf->rot_mat_gamma[0] = cos(roty);
	fdf->rot_mat_gamma[2] = sin(roty);
	fdf->rot_mat_gamma[4] = 1;
	fdf->rot_mat_gamma[6] = - sin(roty);
	fdf->rot_mat_gamma[8] = cos(roty);
	fdf->rot_mat_zeta[0] = cos(rotz);
	fdf->rot_mat_zeta[1] = - sin(rotz);
	fdf->rot_mat_zeta[3] = sin(rotz);
	fdf->rot_mat_zeta[4] = cos(rotz);
	fdf->rot_mat_zeta[8] = 1;
}
