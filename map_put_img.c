/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:56:18 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/09 16:20:28 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_put_img()
{
	t_game	*game_d;
	
	int i;
	int j;
	game_d = get_data();
	i = 0;
	j = 0;
	while(j < game_d->map_size.height)
	{
		while(i < game_d->map_size.width)
		{
			if(game_d->arr[j][i] == '0' || game_d->arr[j][i] == 'P'|| game_d->arr[j][i] == 'C'|| game_d->arr[j][i] == 'E')
				mlx_put_image_to_window(game_d->mlx, game_d->win, game_d->floor.img, i * 32, j * 32);
			if(game_d->arr[j][i] == '1')
				mlx_put_image_to_window(game_d->mlx, game_d->win, game_d->wall.img, i * 32, j * 32);
			if(game_d->arr[j][i] == 'P')
				mlx_put_image_to_window(game_d->mlx, game_d->win, game_d->character.img, i * 32, j * 32);
			if(game_d->arr[j][i] == 'C')
				mlx_put_image_to_window(game_d->mlx, game_d->win, game_d->collect.img, i * 32, j * 32);
			if(game_d->arr[j][i] == 'E')
				mlx_put_image_to_window(game_d->mlx, game_d->win, game_d->exit.img, i * 32, j * 32);
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