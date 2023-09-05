/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hori_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:26:54 by jmoutous          #+#    #+#             */
/*   Updated: 2023/09/05 12:49:04 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	ft_ray_collision_n(t_data *game, int new_x, int new_y)
{
	int	new_x_0;
	int	new_y_0;

	new_x_0 = new_x / BOX_SIZE;
	new_y_0 = new_y / BOX_SIZE;
	if (new_x_0 <= 0 || new_y_0 <= 0
		|| new_x_0 >= game->map_width || new_y_0 >= game->map_height
		|| game->map[new_y_0][new_x_0] != '0')
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
	while (hori.x > 0 && hori.y > 0
		&& hori.x < game->map_width * BOX_SIZE
		&& hori.y < game->map_height * BOX_SIZE
		&& ft_ray_collision_n(game, (int) hori.x, (int) hori.y) == 0)
	{
		hori.depth += delta_depth;
		hori.y += BOX_SIZE;
		hori.x += delta_x;
	}
	return (hori);
}

static int	ft_ray_collision_s(t_data *game, int new_x, int new_y)
{
	int	new_x_0;
	int	new_y_0;

	new_x_0 = (new_x - 1) / BOX_SIZE;
	new_y_0 = (new_y - 1) / BOX_SIZE;
	if (new_x_0 <= 0 || new_y_0 <= 0
		|| new_x_0 >= game->map_width || new_y_0 >= game->map_height
		|| game->map[new_y_0][new_x_0] != '0')
		return (1);
	return (0);
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
	hori.x = game->player_x + hori.depth * cosf(angle) + 1;
	delta_depth = BOX_SIZE / -sinf(angle);
	delta_x = delta_depth * cosf(angle);
	while (hori.x > 0 && hori.y > 0
		&& hori.x < game->map_width * BOX_SIZE
		&& hori.y < game->map_height * BOX_SIZE
		&& ft_ray_collision_s(game, (int) hori.x, (int) hori.y) == 0)
	{
		hori.depth += delta_depth;
		hori.y -= BOX_SIZE;
		hori.x += delta_x;
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
