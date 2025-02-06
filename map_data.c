/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:24 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/06 14:17:34 by didimitr         ###   ########.fr       */
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

}
void	map_data_apnd(char **arr, int file)
{
	t_game	game;
	char	*line;
	int	i;
	int j;

	game = *get_data();
	i = 0;
	j = 0;
	while(j < game.map_size.height)
	{
		line = get_next_line(file);	
		while(line[i] != '\0')
		{
			arr[j][i] = line[i];
			i++;
		}
		j++;
		free(line);
	}
}
void	copy_line(char **arr, char	*line, int j)
{
	int i;
	
	i = 0;
	while(line[i] != '\0')
	{
		arr[j][i] = line[i];
		i++;
	}
}