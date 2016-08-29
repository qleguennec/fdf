/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 15:52:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 00:05:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl/libgnl.h"
#include "libft/libft.h"
#include <limits.h>
#include "fdf.h"

unsigned int	vect_getnbr(t_vect *v, size_t *start)
{
	unsigned long	ret;
	unsigned long	pow;
	char			dig;
	size_t			i;
	size_t			read;

	i = *start;
	while (i < v->used && ((char *)v->data)[i] != ' ')
		i++;
	read = i + 1;
	ret = 0;
	pow = 1;
	while (i != *start)
	{
		dig = ((char *)v->data)[--i];
		if (!ft_isdigit(dig))
			fdf_exit();
		ret += pow * (dig - '0');
		if (ret > UINT_MAX)
			fdf_exit();
		pow *= 10;
	}
	while (((char *)v->data)[read] == ' ')
		read++;
	*start = read;
	return (ret);
}

int				parse_line(t_vect *line, t_fdf *fdf)
{
	size_t			start;
	size_t			x;
	unsigned int	nbr;

	start = 0;
	x = 0;
	while (start < line->used)
	{
		nbr = vect_getnbr(line, &start);
		vect_add(fdf->map, &nbr, sizeof(int));
		x++;
	}
	fdf->y++;
	return (x);
}

void			map_parse(int fd, t_fdf *fdf)
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
		x = parse_line(&line, fdf);
		if (!fdf->x)
			fdf->x = x;
		else if (fdf->x != x)
			fdf_exit();
		line.used = 0;
	}
}
