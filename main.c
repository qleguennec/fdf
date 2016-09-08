/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 15:47:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/09/08 17:59:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libmlx/mlx.h"
#include "fdf.h"

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

int			run(int fd, t_fdf *fdf)
{
	t_vect	map;
	t_vect	proj;
	t_vect	squares;

	ft_bzero(&map, sizeof(map));
	ft_bzero(&proj, sizeof(proj));
	ft_bzero(&squares, sizeof(squares));
	fdf->map = &map;
	fdf->proj = &proj;
	fdf->squares = &squares;
	map_parse(fd, fdf);
	fdf_init(fdf);
	mlx_key_hook(fdf->win, &fdf_keys, fdf);
	mlx_loop_hook(fdf->mlx, &fdf_loop, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_obj	obj;
	t_fdf	fdf;

	ft_bzero(&fdf, sizeof(fdf));
	fd = parse_args(argc, argv);
	fdf.obj = &obj;
	fdf.sz = SZ;
	return (run(fd, &fdf));
}
