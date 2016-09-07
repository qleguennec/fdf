/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 15:52:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/06 19:56:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include "libgnl/libgnl.h"
#include "fdf.h"

static long			get_next_nbr
	(t_vect *v, size_t *start, long ul_pow)
{
	int		dig;

	if (*start == v->used)
		return (0);
	dig = ((char *)v->data)[*start];
	if (ft_isspace(dig))
		return (0);
	if (!ft_isdigit(dig))
		fdf_exit();
	(*start)++;
	return (ul_pow * (dig - '0') + get_next_nbr(v, start, ul_pow / 10));
}

static int			vect_getnbr(t_vect *v, size_t *start, int *nbr)
{
	size_t	i;
	int		neg;
	long	tmp;

	neg = 0;
	while (*start < v->used && ft_isspace(((char *)v->data)[*start]))
		(*start)++;
	if (((char *)v->data)[*start] == '-' && (*start)++)
		neg = 1;
	i = *start;
	while (i < v->used && !ft_isspace(((char *)v->data)[i]))
		i++;
	if (i == *start)
		return (0);
	tmp = (neg ? -1 : 1) * get_next_nbr(v, start, pow(10, i - 1 - *start));
	if (tmp < INT_MIN || tmp > INT_MAX)
		fdf_exit();
	*nbr = (int)tmp;
	return (1);
}

static int				parse_line(t_vect *line, t_fdf *fdf)
{
	size_t			start;
	size_t			x;
	int				nbr;

	start = 0;
	x = 0;
	while (vect_getnbr(line, &start, &nbr))
	{
		vect_add(fdf->map, &nbr, sizeof(int));
		x++;
	}
	fdf->y++;
	return (x);
}

static void				save(t_fdf *fdf, t_vect *max, t_vect *min)
{
	max->used = 0;
	ft_memcpy(max, fdf->proj, sizeof(*max));
	free(min->data);
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
			continue ;
		x = parse_line(&line, fdf);
		if (!fdf->x)
			fdf->x = x;
		else if (fdf->x != x)
			fdf_exit();
		line.used = 0;
	}
	save(fdf
		, line.used > gnl.used ? &line : &gnl
		, line.used > gnl.used ? &gnl : &line);
}
