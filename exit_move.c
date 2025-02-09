/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:38:49 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/09 20:23:54 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_exit_up(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if(data->arr[pos.y - 1][pos.x] == 'E')
		return(true);
	else
		return(false);
}
bool	valid_exit_down(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if(data->arr[pos.y + 1][pos.x] == 'E')
		return(true);
	else
		return(false);
}
bool	valid_exit_left(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if(data->arr[pos.y][pos.x - 1] == 'E')
		return(true);
	else
		return(false);
}
bool	valid_exit_right(t_p_pos pos)
{
	t_game	*data;

	data = get_data();
	if(data->arr[pos.y][pos.x + 1] == 'E')
		return(true);
	else
		return(false);
}