/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:40 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/06 14:17:44 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libraries/libft/sources/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

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

# define PLAYER_SIZE	16
# define BOX_SIZE		80
# define STEP_LENGTH	4

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

typedef struct s_data
{
	char	**map;

	//path to texture
	char	*path_north;
	void	*north;

	char	*path_south;
	void	*south;

	char	*path_west;
	void	*west;

	char	*path_east;
	void	*east;

	//colors
	int		r_floor;
	int		g_floor;
	int		b_floor;

	int		r_ceiling;
	int		g_ceiling;
	int		b_ceiling;

	//player
	int		x_player;
	int		y_player;
	char	direction;//NESW
	float	degree;
	int		show_map;

	void	*mlx_ptr;
	void	*win_ptr;

	//pixel
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_line	line;
}				t_data;

// Game initiation
t_data	*ft_game_init(void);
void	ft_load_textures(t_data *game);

// Utils
void	ft_check_arg(int ac, char **av);
int		ft_quit(t_data *data);
void	ft_error(t_data *data, char *str);
int		ft_key(int key, t_data *game);
void	ft_position_cal(t_data *game, int forward, int strafe);

// Draw
void	ft_refresh_img(t_data *game);
void	ft_draw_map(t_data *game, char **map);
void	ft_render_player(t_data *game, int x, int y);
void	ft_mlx_pixel_put(t_data *game, int x, int y, int color);
void	ft_draw_fov(t_data *game);
void	ft_add_x_line(t_line *line, int x0, int x1, float degree);
void	ft_add_y_line(t_line *line, int y0, int y1, float degree);

// Ray casting
int		ft_ray_collision(t_data *game, int new_x, int new_y);
void	ft_draw_ray(t_data *game, t_line *line, int color);

// Game Play
int		ft_check_collision(t_data *game, int new_x, int new_y);


//parsing
void	fill_map(t_data	*game, char **av);

#endif