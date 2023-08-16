/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:12:36 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/16 14:57:58 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// divide by 4 because BOX_SIZE / MAP_BOX_SIZE = 4;
void	ft_render_player(t_data *game, int x, int y)
{
	int	scale;
	int	i;
	int	j;

	scale = BOX_SIZE / MAP_BOX_SIZE;
	i = -(MAP_PLAYER_SIZE);
	while (i < (MAP_PLAYER_SIZE))
	{
		j = -(MAP_PLAYER_SIZE);
		while (j < (MAP_PLAYER_SIZE))
		{
			if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGTH)
				ft_mlx_pixel_put(game, (x + i) / scale, (y + j) / scale, RED);
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
	while (i < MAP_BOX_SIZE)
	{
		j = 0;
		while (j < MAP_BOX_SIZE)
		{
			if (i == 0 || i == MAP_BOX_SIZE || j == 0 || j == MAP_BOX_SIZE)
				ft_mlx_pixel_put(game, x * MAP_BOX_SIZE + i,
					y * MAP_BOX_SIZE + j, BLACK);
			else
				ft_mlx_pixel_put(game, x * MAP_BOX_SIZE + i,
					y * MAP_BOX_SIZE + j, color);
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
	t_line	line;
	float	angle;
	int		scale;

	scale = BOX_SIZE / MAP_BOX_SIZE;
	angle = game->degree;
	angle -= M_PI / 6;
	while (angle <= game->degree + M_PI / 6)
	{
		ft_add_x_line(&line, game->player_x, WIN_WIDTH / 2, angle);
		ft_add_y_line(&line, game->player_y, WIN_HEIGTH / 2, angle);
		ft_draw_ray(game, &line, GREEN, scale);
		angle += M_PI / WIN_WIDTH;
	}
	ft_add_x_line(&line, game->player_x, WIN_WIDTH / 2, game->degree);
	ft_add_y_line(&line, game->player_y, WIN_HEIGTH / 2, game->degree);
	ft_draw_ray(game, &line, BLUE, scale);
}
