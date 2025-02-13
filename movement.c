/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:28:34 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 16:30:39 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(void)
{
	t_game	*data;
	t_p_pos	pos;

	data = get_data();
	pos = get_p_pos();
	if(valid_exit_up(pos))
		exit(1);
	if(valid_move_up(pos))
	{
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
	if(valid_exit_down(pos))
		exit(1);
	if(valid_move_down(pos))
	{
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
	if(valid_exit_left(pos))
		exit(1);
	if(valid_move_left(pos))
	{
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
	if(valid_exit_right(pos))
		exit(1);
	if(valid_move_right(pos))
	{
		data->arr[pos.y][pos.x] = '0';
		data->arr[pos.y][pos.x + 1] = 'P'; 
	}
}

t_p_pos	get_p_pos()
{
	t_p_pos pos;
	t_game	*data;

	pos.x = 0;
	pos.y = 0;
	data = get_data();
	while(pos.y < data->map_size.h)
	{
		while (pos.x < data->map_size.w)
		{
			if(data->arr[pos.y][pos.x] == 'P')
			{
				return(pos);
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	return(pos);
}
