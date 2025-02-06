/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:38:31 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/06 13:12:44 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_data 
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int win_width;
	int win_height;
} t_data;

typedef struct s_map_size
{
	int	width;
	int height;
} t_map_size;

typedef struct s_game
{
	t_map_size	map_size;
}	t_game;


void map_size(char *map);
int	map_width(int fd);
int	line_lenght(char *line);
int	map_height(int fd);
char	**map_arr(char *map);
void	free_map(char **arr, int i);
char	**map_arr_mal(t_map_size size);
t_game	*get_data(void);

#endif
