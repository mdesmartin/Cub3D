/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:40 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/31 16:50:13 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libraries/libft/sources/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define KEY_ESC 65307
# define KEY_W 65362
# define KEY_S 65364
# define KEY_A 65361
# define KEY_D 65363
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100

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

	void	*mlx_ptr;
	void	*win_ptr;

	//pixel
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


// Game initiation
t_data	*ft_game_init(void);
void	ft_load_textures(t_data *game);

// Utils
void	ft_check_arg(int ac, char **av);
int		ft_quit(t_data *data);
void	ft_error(t_data *data, char *str);
int		ft_key(int key, t_data *game);
void	ft_mlx_pixel_put(t_data *game, int x, int y, int color);

//parsing
void	fill_map(t_data	*game, char **av);
#endif