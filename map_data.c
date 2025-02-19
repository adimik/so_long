/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:24 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/19 20:30:06 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_data(char **arr, char *map)
{
	int	file;

	file = open(map, O_RDONLY);
	if (file < 0)
		return (false);
	map_data_apnd(arr, file);
	return (true);
}

void	map_data_apnd(char **arr, int file)
{
	t_game	*game;
	char	*line;
	int		i;
	int		j;

	game = get_data();
	i = 0;
	j = 0;
	while (j < game->mize.h)
	{
		line = get_next_line(file);
		while (i < game->mize.w)
		{
			arr[j][i] = line[i];
			if (arr[j][i] == 'E')
			{
				game->exit_pos.x = i;
				game->exit_pos.y = j;
			}
			i++;
		}
		i = 0;
		j++;
		free(line);
	}
}

void	valid_obj(int j, int i)
{
	t_game	*data;

	data = get_data();
	if (data->arr[j][i] != 'P' && data->arr[j][i] != 'E'
		&& data->arr[j][i] != 'C' && data->arr[j][i] != '0'
		&& data->arr[j][i] != '1')
	{
		ft_printf("ERROR: invalid object in map.'%c'\n", data->arr[j][i]);
		closewin();
	}
}
