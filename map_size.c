/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:27:24 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/06 13:12:19 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_lenght(char *line)
{
	int	i;
	
	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
		i++;
	return(i);
}

int	map_width(int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	if((line) == NULL)
	{
		free(line);
		return(0);
	}
	i = line_lenght(line);
	while(line != NULL)
	{
		j = line_lenght(line);
		if(i != j)
		{	
			free(line);
			return(0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return(i);
}

int	map_height(int fd)
{
	int	i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while(line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return(i);	
}

void map_size(char *map)
{
	int file;
	t_game	game;

	game = *get_data();
	file = open(map, O_RDONLY);
	if (file == -1)
	{
		printf("Error, fail to open map");
		game.map_size.width = -1;
		game.map_size.height = -1;
		return;
	}
	game.map_size.width = map_width(file);
	close(file);
	file = open(map, O_RDONLY);
	if (file == -1)
	{

		printf("Error, fail to open map");
		game.map_size.width = -1;
		game.map_size.height = -1;
		return;
	}
	game.map_size.height = map_height(file);
	close(file);
}
