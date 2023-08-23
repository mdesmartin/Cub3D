/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:58:06 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/23 11:24:02 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	ft_ray_collision(t_data *game, int new_x, int new_y)
{
	new_x = new_x / BOX_SIZE;
	new_y = new_y / BOX_SIZE;
	if (new_x <= 0 || new_y <= 0
		|| new_x >= game->map_width || new_y >= game->map_height
		|| game->map[new_y][new_x] != '0')
		return (1);
	return (0);
}

static float	ft_vert_col_cos_pos(t_data *game, float angle)
{
	float	depth_vert;
	float	delta_depth;
	float	x;
	float	y;
	float	delta_y;

	x = 0;
	while (x < game->player_x)
		x += BOX_SIZE;
	depth_vert = (x - game->player_x) / cosf(angle);
	y = game->player_y + depth_vert * sinf(angle);
	delta_depth = BOX_SIZE * cosf(angle);
	delta_y = delta_depth * sinf(angle);
	while (ft_ray_collision(game, (int) x, (int) y) != 1)
	{
		x += BOX_SIZE;
		y += delta_y;
		depth_vert += delta_depth;
	}
	return (depth_vert);
}

static float	ft_vert_col_cos_neg(t_data *game, float angle)
{
	float	depth_vert;
	float	delta_depth;
	float	x;
	float	y;
	float	delta_y;

	x = 0;
	while (x < game->player_x)
		x += BOX_SIZE;
	x -= BOX_SIZE;
	depth_vert = (x - game->player_x) / cosf(angle);
	y = game->player_y + depth_vert * sinf(angle);
	delta_depth = BOX_SIZE * -cosf(angle);
	delta_y = delta_depth * sinf(angle);
	while (ft_ray_collision(game, (int) x, (int) y) != 1)
	{
		x += BOX_SIZE;
		y += delta_y;
		depth_vert += delta_depth;
	}
	return (depth_vert);
}

static float	ft_vert_collision(t_data *game, float angle)
{
	float	vert_coll;

	if (cosf(angle) > 0)
	{
		vert_coll = ft_vert_col_cos_pos(game, angle);
		// printf("depth_vert pos = %f\n", vert_coll);
		return (vert_coll);
	}
	else if (cosf(angle) < 0)
	{
		vert_coll = ft_vert_col_cos_neg(game, angle);
		// printf("depth_vert neg = %f\n", vert_coll);
		return (vert_coll);
	}
	else if (cosf(angle) == 0)
		printf("cos == 0\n");
	return (0);
}

float	ft_float_collision(t_data *game)
{
	float	depth_vert;
	// float	depth_hori;

	depth_vert = ft_vert_collision(game, game->degree);
	// depth_hori = ft_hori_collision(game);
	return (depth_vert);
}
