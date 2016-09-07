/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 18:55:08 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/07 21:42:19 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		sort_quicksort(t_square *sq, size_t n)
{
	int			i;
	int			j;
	int			p;
	t_square	tmp;

	if (n < 2)
		return ;
	p = sq[n / 2].z_max;
	i = 0;
	j = n - 1;
	while (42)
	{
		while (sq[i].z_max < p)
			i++;
		while (p < sq[j].z_max)
			j--;
		if (i >= j)
			break ;
		tmp = sq[i];
		sq[i] = sq[j];
		sq[j] = tmp;
		i++;
		j--;
	}
	sort_quicksort(sq, i);
	sort_quicksort(sq + i, n - i);
}
