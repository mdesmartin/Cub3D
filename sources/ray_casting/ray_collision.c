/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:31:23 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/29 17:47:04 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	ft_diagonal_nw_se_collision(t_data *game, int new_x, int new_y)
{
	int	x_0;
	int	y_0;
	int	x_1;
	int	y_1;

	x_0 = (new_x + 1 - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_0 = (new_y - game->map_y * BOX_SIZE) / BOX_SIZE;
	x_1 = (new_x - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_1 = (new_y + 1 - game->map_y * BOX_SIZE) / BOX_SIZE;
	if (game->map[y_0][x_0] == '1' && game->map[y_1][x_1] == '1')
		return (1);
	x_0 = (new_x - 1 - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_0 = (new_y - game->map_y * BOX_SIZE) / BOX_SIZE;
	x_1 = (new_x - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_1 = (new_y - 1 - game->map_y * BOX_SIZE) / BOX_SIZE;
	if (game->map[y_0][x_0] == '1' && game->map[y_1][x_1] == '1')
		return (1);
	return (0);
}

static int	ft_diagonal_sw_ne_collision(t_data *game, int new_x, int new_y)
{
	int	x_0;
	int	y_0;
	int	x_1;
	int	y_1;

	x_0 = (new_x + 1 - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_0 = (new_y - game->map_y * BOX_SIZE) / BOX_SIZE;
	x_1 = (new_x - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_1 = (new_y - 1 - game->map_y * BOX_SIZE) / BOX_SIZE;
	if (game->map[y_0][x_0] == '1' && game->map[y_1][x_1] == '1')
		return (1);
	x_0 = (new_x - 1 - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_0 = (new_y - game->map_y * BOX_SIZE) / BOX_SIZE;
	x_1 = (new_x - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_1 = (new_y + 1 - game->map_y * BOX_SIZE) / BOX_SIZE;
	if (game->map[y_0][x_0] == '1' && game->map[y_1][x_1] == '1')
		return (1);
	return (0);
}

int	ft_ray_collision(t_data *game, int new_x, int new_y)
{
	int	x_0;
	int	y_0;

	x_0 = (new_x - game->map_x * BOX_SIZE) / BOX_SIZE;
	y_0 = (new_y - game->map_y * BOX_SIZE) / BOX_SIZE;
	if (game->map[y_0][x_0] == '1'
		|| ft_diagonal_nw_se_collision(game, new_x, new_y) != 0
		|| ft_diagonal_sw_ne_collision(game, new_x, new_y) != 0)
		return (1);
	return (0);
}
