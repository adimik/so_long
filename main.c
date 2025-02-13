/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:04:48 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 19:23:00 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

int	game(void)
{
	t_game	*data;
	char	*num_moves;

	data = get_data();
	map_put_img();
	num_moves = ft_itoa(data->n_moves);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, num_moves);
	free(num_moves);
	return (0);
}

int	closewin(void)
{
	t_game	*sex;
	int		i;

	sex = get_data();
	i = 0;
	while (i < sex->mize.h)
	{
		free(sex->arr[i]);
		i++;
	}
	free(sex->arr);
	mlx_destroy_image(sex->mlx, sex->character.img);
	mlx_destroy_image(sex->mlx, sex->exit.img);
	mlx_destroy_image(sex->mlx, sex->floor.img);
	mlx_destroy_image(sex->mlx, sex->collect.img);
	mlx_destroy_image(sex->mlx, sex->wall.img);
	mlx_cleanup(sex->mlx);
	exit(1);
}

int	handle_keypress(int keycode)
{
	if (keycode == 65307)
		closewin();
	if (keycode == 119)
		move_up();
	if (keycode == 115)
		move_down();
	if (keycode == 97)
		move_left();
	if (keycode == 100)
		move_right();
	count_map_obj();
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game_data;

	if (argc != 2)
		return (ft_printf("Error\n"));
	game_data = get_data();
	game_data->map_name = argv[1];
	game_data->n_moves = 0;
	game_data->mlx = mlx_init();
	load_textures();
	game_data->arr = map_arr(game_data->map_name);
	map_check();
	game_data->win = mlx_new_window(game_data->mlx, game_data->mize.w * 32,
			game_data->mize.h * 32, "Test");
	mlx_hook(game_data->win, 17, 1L << 0, closewin, NULL);
	mlx_hook(game_data->win, 2, 1L << 0, handle_keypress, NULL);
	mlx_loop_hook(game_data->mlx, game, NULL);
	mlx_loop(game_data->mlx);
	return (0);
}
