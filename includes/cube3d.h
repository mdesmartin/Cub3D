/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:40 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/31 15:01:57 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libraries/libft/sources/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	**description;
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

}				t_data;

// Game initiation
t_data	*ft_game_init(void);

// Utils
void	ft_check_arg(int ac, char **av);
int		ft_quit(t_data *data);
void	ft_error(t_data *data, char *str);

//parsing
void	fill_map(t_data	*game, char **av);

#endif