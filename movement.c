/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:28:34 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 19:10:25 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(void)
{
	t_game	*data;
	t_p_pos	pos;

	data = get_data();
	pos = get_p_pos();
	if (valid_exit_up(pos))
		closewin();
	if (valid_move_up(pos))
	{
		data->n_moves += 1;
		ft_printf("Move count: %d\n", data->n_moves);
		data->arr[pos.y][pos.x] = '0';
		data->arr[pos.y - 1][pos.x] = 'P';
	}
}

void	move_down(void)
{
	t_game	*data;
	t_p_pos	pos;

	data = get_data();
	pos = get_p_pos();
	if (valid_exit_down(pos))
		closewin();
	if (valid_move_down(pos))
	{
		data->n_moves += 1;
		ft_printf("Move count: %d\n", data->n_moves);
		data->arr[pos.y][pos.x] = '0';
		data->arr[pos.y + 1][pos.x] = 'P';
	}
}

void	move_left(void)
{
	t_game	*data;
	t_p_pos	pos;

	data = get_data();
	pos = get_p_pos();
	if (valid_exit_left(pos))
		closewin();
	if (valid_move_left(pos))
	{
		data->n_moves += 1;
		ft_printf("Move count: %d\n", data->n_moves);
		data->arr[pos.y][pos.x] = '0';
		data->arr[pos.y][pos.x - 1] = 'P';
	}
}

void	move_right(void)
{
	t_game	*data;
	t_p_pos	pos;

	data = get_data();
	pos = get_p_pos();
	if (valid_exit_right(pos))
		closewin();
	if (valid_move_right(pos))
	{
		data->n_moves += 1;
		ft_printf("Move count: %d\n", data->n_moves);
		data->arr[pos.y][pos.x] = '0';
		data->arr[pos.y][pos.x + 1] = 'P';
	}
}

t_p_pos	get_p_pos(void)
{
	t_p_pos	pos;
	t_game	*data;

	pos.x = 0;
	pos.y = 0;
	data = get_data();
	while (pos.y < data->mize.h)
	{
		while (pos.x < data->mize.w)
		{
			if (data->arr[pos.y][pos.x] == 'P')
			{
				return (pos);
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	return (pos);
}
