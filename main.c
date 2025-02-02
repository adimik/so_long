/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:04:48 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/02 18:12:00 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data 
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

// ✅ Funkce pro vykreslení jednoho pixelu
void put_pixel(t_data *img, int x, int y, int color)
{
	char *dst;

	// Najdeme adresu pixelu v paměti
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	// Uložíme barvu pixelu
	*(unsigned int*)dst = color;
}
void test(t_data *img)
{
	int l;
	int i;

	l = 0;
	i = 0;
	while(i < 1080)
	{
		while(l < 1920)
		{
			put_pixel(img, l, i, 0xFFFF0000);
			l++;
		}
		l = 0;
		i++;
	}
}
int	main(void)
{
	void *mlx;
	void *win;
	int 	i;
	t_data img;

	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Test");

	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// ✅ Nastavení pixelu na souřadnici (100, 100) na červenou (0xFF0000)
	//put_pixel(&img, 100, 100, 0xFF0000);
	test(&img);

	// ✅ Zobrazení obrázku v okně
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);  // Nekonečná smyčka pro vykreslování
	return (0);
}
