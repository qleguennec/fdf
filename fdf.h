/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 16:07:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/29 18:41:44 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# define VECT_EXIT_FUNCTION	fdf_exit()

typedef struct		s_fdf
{
	size_t			x;
	size_t			y;
	t_vect			*map;
}					t_fdf;

void				map_parse(int fd, t_fdf *fdf);
void				fdf_exit();

#endif
