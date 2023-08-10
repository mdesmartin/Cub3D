/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:12:36 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/10 11:06:47 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_render_player(t_data *game, int x, int y)
{
	int	i;
	int	j;

	i = -PLAYER_SIZE / 2;
	while (i < PLAYER_SIZE / 2)
	{
		j = -PLAYER_SIZE / 2;
		while (j < PLAYER_SIZE / 2)
		{
			if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGTH)
				ft_mlx_pixel_put(game, x + i, y + j, RED);
			j++;
		}
		i++;
	}
}

// square with black sides
void	ft_draw_square(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < BOX_SIZE)
	{
		j = 0;
		while (j < BOX_SIZE)
		{
			if (i == 0 || i == BOX_SIZE || j == 0 || j == BOX_SIZE)
				ft_mlx_pixel_put(game, x * BOX_SIZE + i, y * BOX_SIZE + j,
					BLACK);
			else
				ft_mlx_pixel_put(game, x * BOX_SIZE + i, y * BOX_SIZE + j,
					color);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_data *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				ft_draw_square(game, x, y, SILVER);
			else if (map[y][x] == '0')
				ft_draw_square(game, x, y, WHITE);
			else if (map[y][x] == ' ')
				ft_draw_square(game, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	ft_draw_fov(t_data *game)
{
	float	degree;

	degree = game->degree;
	degree -= M_PI / 6;
	while (degree <= game->degree + M_PI / 6)
	{
		ft_add_x_line(&game->line, game->player_x, WIN_WIDTH / 2, degree);
		ft_add_y_line(&game->line, game->player_y, WIN_HEIGTH / 2, degree);
		ft_draw_ray(game, &game->line, GREEN);
		degree += M_PI / (3 * WIN_WIDTH);
	}
	ft_add_x_line(&game->line, game->player_x, WIN_WIDTH / 2, game->degree);
	ft_add_y_line(&game->line, game->player_y, WIN_HEIGTH / 2, game->degree);
	ft_draw_ray(game, &game->line, BLUE);
}
