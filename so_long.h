/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:38:31 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/13 19:40:48 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_p_pos
{
	int			x;
	int			y;
}				t_p_pos;

typedef struct s_data
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_map_size
{
	int			w;
	int			h;
}				t_map_size;

typedef struct s_obj
{
	int			character;
	int			coins;
	int			exit;
}				t_obj;

typedef struct s_exit_pos
{
	int			y;
	int			x;
}				t_exit_pos;

typedef struct s_game
{
	t_exit_pos	exit_pos;
	t_obj		obj;
	t_map_size	mize;
	char		**arr;
	t_data		floor;
	t_data		wall;
	t_data		character;
	t_data		collect;
	t_data		exit;
	void		*mlx;
	void		*win;
	int			n_moves;
	char		*map_name;
}				t_game;

void			map_size(char *map);
int				map_width(int fd);
int				line_lenght(char *line);
int				map_height(int fd);
char			**map_arr(char *map);
void			free_map(char **arr, int i);
char			**map_arr_mal(t_map_size size);
t_game			*get_data(void);
bool			map_data(char **arr, char *map);
void			map_data_apnd(char **arr, int file);
void			map_put_img(void);
t_data			load_xpm(const char *path, void *mlx);
void			load_textures(void);
void			move_up(void);
void			move_down(void);
void			move_left(void);
void			move_right(void);
bool			valid_move_up(t_p_pos pos);
bool			valid_move_down(t_p_pos pos);
bool			valid_move_left(t_p_pos pos);
bool			valid_move_right(t_p_pos pos);
bool			valid_exit_up(t_p_pos pos);
bool			valid_exit_down(t_p_pos pos);
bool			valid_exit_left(t_p_pos pos);
bool			valid_exit_right(t_p_pos pos);
t_p_pos			get_p_pos(void);
void			map_check(void);
void			count_map_obj(void);
void			check_map_obj(void);
void			check_surr(void);
int				coin_access(t_game *data, int y, int x);
int				closewin(void);
#endif
