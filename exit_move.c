/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:38:49 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 17:41:19 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_exit_up(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if (data->exit_pos.x == pos.x && data->exit_pos.y == pos.y - 1
		&& data->obj.coins == 0)
		return (true);
	else
		return (false);
}

bool	valid_exit_down(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if (data->exit_pos.x == pos.x && data->exit_pos.y == pos.y + 1
		&& data->obj.coins == 0)
		return (true);
	else
		return (false);
}

bool	valid_exit_left(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if (data->exit_pos.x == pos.x - 1 && data->exit_pos.y == pos.y
		&& data->obj.coins == 0)
		return (true);
	else
		return (false);
}

bool	valid_exit_right(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if (data->exit_pos.x == pos.x + 1 && data->exit_pos.y == pos.y
		&& data->obj.coins == 0)
		return (true);
	else
		return (false);
}
