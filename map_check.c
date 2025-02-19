/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:06:50 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/19 20:30:40 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(void)
{
	t_game	*data;
	int		i;
	t_p_pos	pos;

	pos = get_p_pos();
	i = 0;
	data = get_data();
	count_map_obj();
	check_map_obj();
	check_surr();
	i = coin_access(data, pos.y, pos.y);
	if (i != data->obj.coins)
	{
		ft_printf("Error: Path not valid.\n");
		closewin();
	}
	map_data(data->arr, data->map_name);
}

void	count_map_obj(void)
{
	int		j;
	int		i;
	t_game	*data;

	j = 0;
	i = 0;
	data = get_data();
	data->obj.coins = 0;
	while (j < data->mize.h - 1)
	{
		while (i < data->mize.w)
		{
			if (data->arr[j][i] == 'P')
				data->obj.character += 1;
			if (data->arr[j][i] == 'C')
				data->obj.coins += 1;
			if (data->arr[j][i] == 'E')
				data->obj.exit += 1;
			valid_obj(j, i);
			i++;
		}
		i = 0;
		j = j + 1;
	}
}

void	check_map_obj(void)
{
	t_game	*data;

	data = get_data();
	if (data->obj.character != 1)
	{
		ft_printf("%d\n", data->obj.character);
		ft_printf("Error \nWrong amount of characters\n");
		closewin();
	}
	if (data->obj.exit != 1)
	{
		ft_printf("Error \nWrong amount of exit\n");
		closewin();
	}
	if (data->obj.coins == 0)
	{
		ft_printf("Error \nWrong amount of coins");
		closewin();
	}
}

void	check_surr(void)
{
	t_game	*data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data = get_data();
	while (i < data->mize.w)
	{
		if (data->arr[j][i] != '1' || data->arr[data->mize.h - 1][i] != '1')
		{
			ft_printf("Error: map not surrounded by wall\n");
			closewin();
		}
		i++;
	}
	while (j < data->mize.h)
	{
		if (data->arr[j][i - 1] != '1' || data->arr[j][0] != '1')
		{
			ft_printf("Error: map not surrounded by wall\n");
			closewin();
		}
		j++;
	}
}

int	coin_access(t_game *data, int y, int x)
{
	int		i;
	char	c;

	i = 0;
	c = data->arr[y][x];
	if (c != '0' && c != 'C' && c != 'E' && c != 'P')
		return (i);
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
	return (i);
}
