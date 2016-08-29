/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 15:47:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/08/30 00:05:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft/libft.h"

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
	fdf_init(&fdf);
	return (0);
}
