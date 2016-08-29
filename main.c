/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 15:47:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/29 19:16:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libvect/libvect.h"
#include "libft/libft.h"
#include "fdf.h"

void		test_parsing(t_fdf *fdf)
{
	size_t	x;
	int		nbr;

	x = 0;
	while (fdf->y)
	{
		while (x < fdf->map->used)
		{
			ft_memcpy(&nbr, fdf->map->data + x, 4);
			printf("%u\n", nbr);
			x += 4;
		}
		fdf->y--;
	}
}

int			parse_args(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		fdf_exit();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		fdf_exit();
	return (fd);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_vect	map;
	t_fdf	fdf;

	ft_bzero(&fdf, sizeof(fdf));
	ft_bzero(&map, sizeof(map));
	fd = parse_args(argc, argv);
	fdf.map = &map;
	map_parse(fd, &fdf);
	printf("map size: %lu\n", map.used);
	test_parsing(&fdf);
	return (0);
}
