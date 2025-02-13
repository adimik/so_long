/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:56:18 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 17:49:11 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tw(void *img, int x, int y)
{
	t_game	*g;

	g = get_data();
	mlx_put_image_to_window(g->mlx, g->win, img, x, y);
}

void	map_put_img(void)
{
	t_game	*g;
	int		i;
	int		j;

	g = get_data();
	i = 0;
	j = 0;
	while (j < g->mize.h)
	{
		while (i < g->mize.w)
		{
			tw(g->floor.img, i * 32, j * 32);
			if (g->arr[j][i] == '1')
				tw(g->wall.img, i * 32, j * 32);
			if (g->arr[j][i] == 'P')
				tw(g->character.img, i * 32, j * 32);
			if (g->arr[j][i] == 'C')
				tw(g->collect.img, i * 32, j * 32);
			if (g->exit_pos.x == i && g->exit_pos.y == j && g->obj.coins == 0)
				tw(g->exit.img, i * 32, j * 32);
			i++;
		}
		i = 0;
		j++;
	}
}

void	load_textures(void)
{
	t_game	*data;

	data = get_data();
	data->floor = load_xpm("assets/floor.xpm", data->mlx);
	data->wall = load_xpm("assets/wall.xpm", data->mlx);
	data->character = load_xpm("assets/character.xpm", data->mlx);
	data->collect = load_xpm("assets/coin.xpm", data->mlx);
	data->exit = load_xpm("assets/exit.xpm", data->mlx);
}
