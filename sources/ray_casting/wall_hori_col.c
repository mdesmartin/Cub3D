/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hori_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:26:54 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/23 14:10:09 by jmoutous         ###   ########lyon.fr   */
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

static t_col_point	ft_hori_col_sin_pos(t_data *game, float angle)
{
	t_col_point	hori;
	float		delta_depth;
	float		delta_x;

	hori.y = 0;
	while (hori.y < game->player_y)
		hori.y += BOX_SIZE;
	hori.depth = (hori.y - game->player_y) / sinf(angle);
	hori.x = game->player_x + hori.depth * cosf(angle);
	delta_depth = BOX_SIZE / sinf(angle);
	delta_x = delta_depth * cosf(angle);
	while (ft_ray_collision(game, (int) hori.x, (int) hori.y) != 1)
	{
		hori.y += BOX_SIZE;
		hori.x += delta_x;
		if (hori.x < 0 || hori.y < 0
			|| hori.x > game->map_width || hori.y > game->map_height)
			break ;
		hori.depth += delta_depth;
	}
	return (hori);
}

static t_col_point	ft_hori_col_sin_neg(t_data *game, float angle)
{
	t_col_point	hori;
	float		delta_depth;
	float		delta_x;

	hori.y = 0;
	while (hori.y < game->player_y)
		hori.y += BOX_SIZE;
	hori.y -= BOX_SIZE;
	hori.depth = (hori.y - game->player_y) / sinf(angle);
	hori.x = game->player_x + hori.depth * cosf(angle);
	delta_depth = BOX_SIZE / -sinf(angle);
	delta_x = delta_depth * cosf(angle);
	while (ft_ray_collision(game, (int) hori.x, (int) hori.y) != 1)
	{
		hori.y += BOX_SIZE;
		hori.x += delta_x;
		if (hori.x < 0 || hori.y < 0
			|| hori.x > game->map_width || hori.y > game->map_height)
			break ;
		hori.depth += delta_depth;
	}
	return (hori);
}

t_col_point	ft_hori_collision(t_data *game, float angle)
{
	t_col_point	horizontal;

	if (sinf(angle) > 0)
	{
		horizontal = ft_hori_col_sin_pos(game, angle);
		horizontal.face = 'N';
	}
	else if (sinf(angle) < 0)
	{
		horizontal = ft_hori_col_sin_neg(game, angle);
		horizontal.face = 'S';
	}
	else
	{
		horizontal.depth = 0;
		horizontal.face = '\0';
		horizontal.x = 0;
		horizontal.y = 0;
	}
	return (horizontal);
}
