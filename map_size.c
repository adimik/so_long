/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:27:24 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/19 20:29:58 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_lenght(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

int	map_width(int fd)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		j = line_lenght(line);
		if (j > 0)
		{
			if (i < 0)
				i = j;
			else if (j != i)
				return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (i < 0)
		return (0);
	else
		return (i);
}

int	map_height(int fd)
{
	int		total;
	int		empty_count;
	int		len;
	char	*line;

	total = 0;
	empty_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = line_lenght(line);
		if (len > 0)
		{
			total += 1 + empty_count;
			empty_count = 0;
		}
		else
			empty_count++;
		free(line);
		line = get_next_line(fd);
	}
	return (total);
}

void	map_size(char *map)
{
	int		file;
	t_game	*game;

	game = get_data();
	file = open(map, O_RDONLY);
	if (file == -1)
	{
		printf("Error, fail to open map");
		game->mize.w = -1;
		game->mize.h = -1;
		closewin();
	}
	game->mize.w = map_width(file);
	close(file);
	file = open(map, O_RDONLY);
	if (file == -1)
	{
		printf("Error, fail to open map");
		game->mize.w = -1;
		game->mize.h = -1;
		closewin();
	}
	game->mize.h = map_height(file);
	close(file);
}
