/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:04:48 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/30 18:08:07 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


typedef struct s_data 
{
	void *img;
	char *addr;
	int	pixel_per_bite;
	int	line_lenght;
	int endian;
}	t_data;


int	main(void)
{
	void *mlx;
	t_data img;

	mlx = mlx_init();
	img.img = mlx_new_window(mlx, 1920, 1080, "Test");
	mlx_loop(mlx);
	return(1);
}