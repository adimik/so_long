/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:06:50 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 16:30:39 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(void)
{
	t_game	*data;
	bool	valid;
	int	i;

	i = 0;
	data = get_data();
	count_map_obj();
	valid = check_map_obj();
	ft_printf("kontrola spravneho poctu obj na mape: %d\n", valid);
	valid = check_surr();
	ft_printf("mapa spravne obklopena zdi okolo: %d\n", valid);
	i = coin_access(data, 1, 1);
	map_data(data->arr, "maps/map.ber");
	ft_printf("zadano character: %d\nzadano coinu: %d\nzadano exitu: %d\n", data->obj.character, data->obj.coins, data->obj.exit);
	ft_printf("pocet nalezenych coinu na mape: %d\n", i);
}
void	count_map_obj(void)
{
	int		j;
	int		i;
	t_game	*data;

	j = 0;
	i = 0;
	data = get_data();
	while (j < data->map_size.h)
	{
		while (i < data->map_size.w)
		{
			if (data->arr[j][i] == 'P')
				data->obj.character += 1;
			if (data->arr[j][i] == 'C')
				data->obj.coins += 1;
			if (data->arr[j][i] == 'E')
				data->obj.exit += 1;
			i++;
		}
		i = 0;
		j++;
	}
}
bool	check_map_obj(void)
{
	t_game	*data;

	data = get_data();
	if (data->obj.character != 1)
		return (false);
	if (data->obj.exit != 1)
		return (false);
	else
		return (true);
}
bool	check_surr(void)
{
	t_game	*data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data = get_data();
	while (i < data->map_size.w)
	{
		if (data->arr[j][i] != '1' || data->arr[data->map_size.h - 1][i] != '1')
			return (false);
		i++;
	}
	while (j < data->map_size.h)
	{
		if (data->arr[j][i - 1] != '1' || data->arr[j][0] != '1')
			return (false);
		j++;
	}
	return (true);
}
int	coin_access(t_game *data, int y, int x)
{
	int i;
	char c;


	i = 0;
    c = data->arr[y][x];
    if (c != '0' && c != 'C' && c != 'E' && c != 'P')
        return i;
    if (c == 'C') 
	{
		i++;
		data->arr[y][x] = 'V';
	}
	if (c == '0')
		data->arr[y][x] = 'v';
	if (c == 'E')
		data->arr[y][x] = 'e';
	if (c == 'P')
		data->arr[y][x] = 'p';
	i += coin_access(data, y + 1, x);
    i += coin_access(data, y - 1, x);
    i += coin_access(data, y, x + 1);
    i += coin_access(data, y, x - 1);
	return(i);
}

