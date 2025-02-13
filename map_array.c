/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:48:29 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 16:30:24 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_arr(char *map)
{
	t_game	*game;
	char	**arr;

	game = get_data();
	map_size(map);
	arr = map_arr_mal(game->map_size);
	if (arr == NULL)
		return (NULL);
	if (!map_data(arr, map))
		return (NULL);
	game->arr = arr;
	return (arr);
}

char	**map_arr_mal(t_map_size size)
{
	int		i;
	char	**arr;

	i = 0;
	arr = malloc(size.h * sizeof(char *));
	while (i < size.h)
	{
		arr[i] = malloc((size.w + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free_map(arr, i);
			return (NULL);
		}
		arr[i][size.w] = '\0';
		i++;
	}
	return (arr);
}
void	free_map(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}
