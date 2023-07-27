/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:40 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/19 13:38:01 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "libft/sources/libft.h"
# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_data;

// Game initiation
t_data	*ft_game_init(void);

// Utils
void	ft_check_arg(int ac, char **av);
int		ft_quit(t_data *data);
void	ft_error(t_data *data, char *str);

#endif