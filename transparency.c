/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:06:46 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 17:40:19 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	apply_transparency(int *src, int *dst, int pixel_count)
{
	int	i;

	i = 0;
	while (i < pixel_count)
	{
		if ((src[i] & 0x00FFFFFF) == 0)
			dst[i] = src[i] & 0x00FFFFFF;
		else
			dst[i] = src[i] | 0xFF000000;
		i++;
	}
}

static void	*create_transparent_copy(void *mlx, void *img, int width,
		int height)
{
	void	*new_img;
	int		*data;
	int		*new_data;
	t_data	info;

	new_img = mlx_new_image_alpha(mlx, width, height);
	if (!new_img)
	{
		mlx_destroy_image(mlx, img);
		exit(EXIT_FAILURE);
	}
	data = (int *)mlx_get_data_addr(img, &info.bits_per_pixel,
			&info.line_length, &info.endian);
	new_data = (int *)mlx_get_data_addr(new_img, &info.bits_per_pixel,
			&info.line_length, &info.endian);
	apply_transparency(data, new_data, width * height);
	return (new_img);
}

t_data	load_xpm(const char *path, void *mlx)
{
	void	*img;
	void	*transparent_img;
	int		width;
	int		height;
	t_data	data;

	img = mlx_xpm_file_to_image(mlx, (char *)path, &width, &height);
	if (!img)
		exit(EXIT_FAILURE);
	transparent_img = create_transparent_copy(mlx, img, width, height);
	mlx_destroy_image(mlx, img);
	data.img = transparent_img;
	data.addr = (int *)mlx_get_data_addr(transparent_img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	data.width = width;
	data.height = height;
	return (data);
}

void	free_tdata(t_data image)
{
	if (!image.img)
		return ;
	mlx_destroy_image(get_data()->mlx, image.img);
}
