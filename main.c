/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:04:48 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 16:30:17 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

int game()
{

	
	map_put_img();
	return 0;
}

int closewin()
{
	exit(1);
}
int	handle_keypress(int keycode)
{
	if(keycode == 65307)
		exit(1);
	if(keycode == 119)
		move_up();
	if(keycode == 115)
		move_down();
	if(keycode == 97)
		move_left();
	if(keycode == 100)
		move_right();		
	return(0);
}
int	main(void)
{
	t_game	*game_data;
	int		i;


	i = 0;

	game_data = get_data();
	game_data->mlx = mlx_init();
	load_textures();
	game_data->arr = map_arr("maps/map.ber");
	map_check();
	printf("%d, %d, %d\n", game_data->obj.character, game_data->obj.coins, game_data->obj.exit);
	game_data->win = mlx_new_window(game_data->mlx, game_data->map_size.w * 32, game_data->map_size.h * 32, "Test");
	mlx_hook(game_data->win, 17, 1L << 0, closewin, NULL);
	mlx_hook(game_data->win, 2, 1L << 0, handle_keypress, NULL);
	mlx_loop_hook(game_data->mlx, game, NULL);

	mlx_loop(game_data->mlx);
	return (0);
}
