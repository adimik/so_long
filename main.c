/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:04:48 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/05 16:51:10 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void *mlx;
	void *win;
	int 	i;
	t_data img;

	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 32, 32, "Test");

	img.img = mlx_new_image(mlx, 32, 32);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.win_width = 32;
	img.win_height = 32;

	img.img = mlx_xpm_file_to_image(mlx, "tile.xpm", &img.win_width, &img.win_height);
	map_size("maps/map1.ber");
	//mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	//mlx_loop(mlx);
	return (0);
}
