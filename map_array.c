/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:48:29 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/06 13:27:32 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_arr(char *map)
{
	t_game data;
	char **arr;
	
	data = *get_data();
	map_size(map);
	arr = map_arr_mal(data.map_size);
	if(arr == NULL)
		return(NULL);
	if(!map_data(arr, map))
		return(NULL);
	
}

char	**map_arr_mal(t_map_size size)
{
	int	i;
	
	i = 0;
	char **arr = malloc(size.height * sizeof(char *));
	while (i < size.height)
	{
		arr[i] = malloc((size.width + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free_map(arr, i);
			return(NULL);
		}
		arr[i][size.width] = '\0';
		i++;
	}
	return(arr);
}
void	free_map(char **arr, int i)
{
	int  j;

	j = 0;

	while(j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}
