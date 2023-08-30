/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:57:10 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/30 15:04:13 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/***********************************  MOVE  ***********************************/

typedef struct s_movements
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	mouse_left;
	bool	mouse_right;
	bool	i;
	bool	j;
	bool	k;
	bool	l;
}			t_movements;

/***********************************  MAIN  ***********************************/

typedef struct s_data
{
	char		**map;
	int			map_height;
	int			map_width;

	char		*path_north;
	char		*path_south;
	char		*path_west;
	char		*path_east;
	void		*north;
	void		*south;
	void		*west;
	void		*east;

	int			floor_color;
	int			ceiling_color;

	char		player_direction;
	float		degree;
	int			show_map;
	int			player_x;
	int			player_y;

	void		*mlx_ptr;
	void		*win_ptr;

	char		*addr;
	void		*img;
	float		screen_dst;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			map_x;
	int			map_y;
	t_movements	move;
}				t_data;

/**********************************  PARSING  *********************************/

typedef struct s_parsing
{
	char	**description;

	int		map_north;
	int		map_south;
	int		map_east;
	int		map_west;
}				t_parsing;

/***********************************  DRAW  ***********************************/

typedef struct s_line
{
	float	dx;
	float	dy;
	float	x_f;
	float	y_f;
	float	e;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		sx;
	int		sy;
}				t_line;

typedef struct s_point
{
	float	distance;
	int		x;
	int		y;
}				t_point;

typedef struct s_col_point
{
	float	depth;
	float	x;
	float	y;
	char	face;
}				t_col_point;

typedef struct s_display_line
{
	char		face;
	float		x_wall;
	int			x_win;
	int			wall_line_height;
	t_img		*wall;
}				t_display_line;

#endif
