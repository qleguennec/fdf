/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 18:55:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 13:11:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v2		v2_abs(t_v2 a)
{
	t_v2	b;

	b.x = ABS(a.x);
	b.y = ABS(a.y);
	return (b);
}
