/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:16:24 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/09 18:23:56 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_move_up(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if(data->arr[pos.y - 1][pos.x] == '1')
		return(false);
	else
		return(true);
}
bool	valid_move_down(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if(data->arr[pos.y + 1][pos.x] == '1')
		return(false);
	else
		return(true);
}
bool	valid_move_left(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if(data->arr[pos.y][pos.x - 1] == '1')
		return(false);
	else
		return(true);
}
bool	valid_move_right(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if(data->arr[pos.y][pos.x + 1] == '1')
		return(false);
	else
		return(true);
}