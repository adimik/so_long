/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:24 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/07 12:34:54 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_data(char **arr, char *map)
{
	int	file;

	file = open(map, O_RDONLY);
	if(file < 0)	
		return(false);
	map_data_apnd(arr, file);
	return(true);
}
void	map_data_apnd(char **arr, int file)
{
	t_game	*game;
	char	*line;
	int	i;
	int j;

	game = get_data();
	i = 0;
	j = 0;
	while(j < game->map_size.height)
	{
		line = get_next_line(file);	
		while(i < game->map_size.width)
		{
			arr[j][i] = line[i];
			printf("%c", arr[j][i]);
			i++;
		}
		i = 0;
		printf("\n");
		j++;
		free(line);
	}
}
