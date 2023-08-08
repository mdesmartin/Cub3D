/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:40 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/03 16:53:18 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libraries/libft/sources/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_parsing
{
	char	**description;

	int		map_north;
	int		map_south;
	int		map_east;
	int		map_west;

	int		first_wall_x;
	int		first_wall_y;
	
	unsigned char	*floor_color;
	unsigned char 	*ceiling_color;
}				t_parsing;

typedef struct s_data
{
	char	**map;

	//path to texture
	char 	*path_north;
	void 	*north;
	
	char 	*path_south;
	void 	*south;

	char 	*path_west;
	void 	*west;
	
	char 	*path_east;
	void 	*east;

	//colors
	int	floor_color;
	int	ceiling_color;
	
	//player
	int		player_x;
	int		player_y;
	char	player_direction;//NESW
	
	void	*mlx_ptr;
	void	*win_ptr;

}				t_data;

// Game initiation
t_data	*ft_game_init(void);

// Utils
void	ft_check_arg(int ac, char **av);
int		ft_quit(t_data *data);
void	ft_error(t_data *data, char *str);

//parsing
int		parsing(t_data	*game, char **av);
void	fill_map(t_data	*game, char **av);
int		is_whitespace(char c);
int		is_map_symbol(char c);
void	*ft_free_tab(char **tab);
void	get_map_cardinal_limits(t_parsing *parsed);
int		get_description(t_parsing *parsed, char **av);
int		check_elements(t_parsing *parsed);
int		check_map(t_parsing *parsed);
int		get_elements(t_data *game, t_parsing *parsed);
int		get_map(t_data *game, t_parsing *parsed);

#endif