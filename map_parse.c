/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 15:52:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/01 13:11:06 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include "libgnl/libgnl.h"
#include "fdf.h"

static unsigned int		get_next_nbr
	(t_vect *v, size_t *start, unsigned long ul_pow)
{
	int		dig;

	if (*start == v->used)
		return (0);
	dig = ((char *)v->data)[*start];
	if (dig == ' ')
		return (0);
	if (!ft_isdigit(dig))
		fdf_exit();
	(*start)++;
	return (ul_pow * (dig - '0') + get_next_nbr(v, start, ul_pow / 10));
}

static unsigned int		vect_getnbr(t_vect *v, size_t *start)
{
	size_t	i;

	while (*start < v->used && ((char *)v->data)[*start] == ' ')
		(*start)++;
	i = *start;
	while (i < v->used && ((char *)v->data)[i] != ' ')
		i++;
	if (i == *start)
		return (-1);
	return (get_next_nbr(v, start, pow(10, i - 1 - *start)));
}

static int				parse_line(t_vect *line, t_fdf *fdf)
{
	size_t			start;
	size_t			x;
	unsigned int	nbr;

	start = 0;
	x = 0;
	while (start < line->used)
	{
		nbr = vect_getnbr(line, &start);
		if (nbr == (unsigned int)-1)
			break ;
		vect_add(fdf->map, &nbr, sizeof(int));
		x++;
	}
	fdf->y++;
	return (x);
}

void					map_parse(int fd, t_fdf *fdf)
{
	t_vect		line;
	t_vect		gnl;
	int			gnl_ret;
	size_t		x;

	ft_bzero(&line, sizeof(line));
	ft_bzero(&gnl, sizeof(gnl));
	while ((gnl_ret = get_next_line(fd, &gnl, &line)) != 0)
	{
		if (gnl_ret < 0)
			fdf_exit();
		if (!line.used)
			fdf_exit();
		x = parse_line(&line, fdf);
		if (!fdf->x)
			fdf->x = x;
		else if (fdf->x != x)
			fdf_exit();
		line.used = 0;
	}
	free(line.data);
	free(gnl.data);
}
