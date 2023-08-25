/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_vert_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:54:25 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/25 13:30:52 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	ft_ray_collision(t_data *game, int new_x, int new_y)
{
	int	new_x_0;
	int	new_y_0;

	new_x_0 = new_x / BOX_SIZE;
	new_y_0 = new_y / BOX_SIZE;
	if (new_x_0 <= 0 || new_y_0 <= 0
		|| new_x_0 >= game->map_width || new_y_0 >= game->map_height
		|| game->map[new_y_0][new_x_0] != '0')
		return (1);
	new_x_0 = (new_x - 1) / BOX_SIZE;
	new_y_0 = (new_y - 1) / BOX_SIZE;
	if (new_x_0 <= 0 || new_y_0 <= 0
		|| new_x_0 >= game->map_width || new_y_0 >= game->map_height
		|| game->map[new_y_0][new_x_0] != '0')
		return (1);
	return (0);
}

static t_col_point	ft_vert_col_cos_pos(t_data *game, float angle)
{
	t_col_point	vert;
	float		delta_depth;
	float		delta_y;

	vert.x = 0;
	while (vert.x < game->player_x)
		vert.x += BOX_SIZE;
	vert.depth = (vert.x - game->player_x) / cosf(angle);
	vert.y = game->player_y + vert.depth * sinf(angle);
	delta_depth = BOX_SIZE / cosf(angle);
	delta_y = delta_depth * sinf(angle);
	while (vert.x > 0 && vert.y > 0
		&& vert.x < game->map_width * BOX_SIZE
		&& vert.y < game->map_height * BOX_SIZE
		&& ft_ray_collision(game, (int) vert.x, (int) vert.y) == 0)
	{
		vert.depth += delta_depth;
		vert.x += BOX_SIZE;
		vert.y += delta_y;
	}
	return (vert);
}

static t_col_point	ft_vert_col_cos_neg(t_data *game, float angle)
{
	t_col_point	vert;
	float		delta_depth;
	float		delta_y;

	vert.x = 0;
	while (vert.x < game->player_x)
		vert.x += BOX_SIZE;
	vert.x -= BOX_SIZE;
	vert.depth = (vert.x - game->player_x) / cosf(angle);
	vert.y = game->player_y + vert.depth * sinf(angle) + 1;
	delta_depth = BOX_SIZE / -cosf(angle);
	delta_y = delta_depth * sinf(angle);
	while (vert.x > 0 && vert.y > 0
		&& vert.x < game->map_width * BOX_SIZE
		&& vert.y < game->map_height * BOX_SIZE
		&& ft_ray_collision(game, (int) vert.x, (int) vert.y) == 0)
	{
		vert.depth += delta_depth;
		vert.x -= BOX_SIZE;
		vert.y += delta_y;
	}
	return (vert);
}

t_col_point	ft_vert_collision(t_data *game, float angle)
{
	t_col_point	verticale;

	if (cosf(angle) > 0)
	{
		verticale = ft_vert_col_cos_pos(game, angle);
		verticale.face = 'W';
	}
	else if (cosf(angle) < 0)
	{
		verticale = ft_vert_col_cos_neg(game, angle);
		verticale.face = 'E';
	}
	else
	{
		verticale.depth = 0;
		verticale.face = '\0';
		verticale.x = 0;
		verticale.y = 0;
	}
	return (verticale);
}
