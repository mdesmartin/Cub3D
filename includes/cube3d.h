/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:40 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/16 15:47:28 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libraries/libft/sources/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include <sys/time.h>//surement a supprimer rapport a getimeofday pour le fps

# define WIN_WIDTH 1280
# define WIN_HEIGTH 720
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_M 109
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define AQUA		0x00ffff
# define BLACK		0x000000 	
# define BLUE		0x0000ff
# define FUCHSIA	0xff00ff
# define GRAY		0x808080
# define GREEN		0x008000
# define LIME		0x00ff00
# define MAROON		0x800000
# define NAVY		0x000080
# define OLIVE		0x808000
# define ORANGE		0xffa500
# define PURPLE		0x800080
# define RED		0xff0000
# define SILVER		0xc0c0c0
# define TEAL		0x008080
# define WHITE		0xffffff
# define YELLOW		0xffff00

# define PLAYER_SIZE		16
# define BOX_SIZE			128
# define STEP_LENGTH		8
# define MAP_BOX_SIZE		16
# define MAP_PLAYER_SIZE	8

typedef struct s_parsing
{
	char	**description;

	int		map_north;
	int		map_south;
	int		map_east;
	int		map_west;
}				t_parsing;

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

typedef struct s_data
{
	char	**map;

	char	*path_north;
	char	*path_south;
	char	*path_west;
	char	*path_east;
	void	*north;
	void	*south;
	void	*west;
	void	*east;

	int		floor_color;
	int		ceiling_color;

	char	player_direction;
	float	degree;
	int		show_map;
	int		player_x;
	int		player_y;

	void	*mlx_ptr;
	void	*win_ptr;

	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_display_line
{
	char		face; // N, S, E, W
	float		x_wall; //horizontal percentage of the wall lengh size where the line take place
	int			x_win; //where to display on the screen this line
	int			wall_line_height; //heigh of the wall's line we gonna print
	t_img		*wall;
}				t_display_line;

/*****************************  GAME INITIATION  ******************************/

t_data	*ft_game_init(void);
void	ft_load_textures(t_data *game);

/***********************************  UTILS  **********************************/

void	ft_check_arg(int ac, char **av);
void	ft_free_tab(char **tab);
int		ft_quit(t_data *data);
void	ft_error(t_data *data, char *str);
int		ft_key(int key, t_data *game);
void	ft_position_cal(t_data *game, int forward, int strafe);
void	free_main(t_data	*game);
void	main_parsing_test(t_data	*game);

/***********************************  DRAW  ***********************************/

void	ft_draw_floor_ceiling(t_data *game);
int		ft_refresh_img(t_data *game);
void	ft_draw_map(t_data *game, char **map);
void	ft_render_player(t_data *game, int x, int y);
void	ft_mlx_pixel_put(t_data *game, int x, int y, int color);
void	ft_draw_fov(t_data *game);
void	ft_add_x_line(t_line *line, int x0, int x1, float degree);
void	ft_add_y_line(t_line *line, int y0, int y1, float degree);
void	ft_draw_3d(t_data *game);
float	ft_wall_position(t_point point, char face);
char	ft_wall_face(float x, float y);
void	print_line(t_data *game, t_display_line line);

/********************************  RAY CASTING  *******************************/

t_point	ft_wall_collision(t_data *game, t_line *line);
int		ft_ray_collision(t_data *game, int new_x, int new_y);
void	ft_draw_ray(t_data *game, t_line *line, int color, int scale);

/*********************************  GAMEPLAY  *********************************/

int		ft_check_collision(t_data *game, int new_x, int new_y);

/**********************************  PARSING  *********************************/

int		check_elements(t_parsing *parsed);
int		check_map(t_parsing *parsed);
void	fill_map(t_data	*game, char **av);
int		get_color_code(t_parsing *parsed, char *element, int size, int *color);
int		get_description(t_parsing *parsed, char **av);
int		get_elements(t_data *game, t_parsing *parsed);
int		get_map(t_data *game, t_parsing *parsed);
int		get_map_cardinal_limits(t_parsing *parsed);
int		get_player(t_data *game, t_parsing *parsed);
int		is_cardinal_point(char c);
int		is_map_symbol(char c);
int		is_whitespace(char c);
int		is_whitespace_or_end(char c);
int		parsing(t_data	*game, char **av);

#endif
