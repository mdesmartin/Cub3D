/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:42:00 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/03 17:52:08 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


int	ft_check_collision(t_data *game, int new_x, int new_y)
{
	int	player_radius;
	int	new_y_w;
	int	new_y_e;
	int	new_x_n;
	int	new_x_s;

	player_radius = PLAYER_SIZE / 2;
	if (new_x - player_radius < 0 || new_x + player_radius > 1280
		|| new_y - player_radius < 0 || new_y + player_radius > 720)
		return (1);
	new_y_w = (new_y + player_radius - 1) / 80;
	new_y_e = (new_y - player_radius) / 80;
	new_x_n = (new_x - player_radius) / 80;
	new_x_s = (new_x + player_radius - 1) / 80;
	if (game->map[new_y_w][new_x_n] == '1'
		|| game->map[new_y_e][new_x_n] == '1'
		|| game->map[new_y_w][new_x_s] == '1'
		|| game->map[new_y_e][new_x_s] == '1')
		return (1);
	return (0);
}
