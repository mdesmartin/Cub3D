/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:12:36 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/29 10:45:12 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_map_size(t_data *game)
{
	game->map_height = 0;
	game->map_width = 0;
	while (game->map[game->map_height])
		game->map_height++;
	while (game->map[0][game->map_width])
		game->map_width++;
}

void	ft_render_player(t_data *game, int x, int y)
{
	static const int	scale = BOX_SIZE / MAP_BOX_SIZE;
	int					i;
	int					j;

	x = x + game->map_x * BOX_SIZE;
	y = y + game->map_y * BOX_SIZE;
	i = -(MAP_PLAYER_SIZE);
	while (i < (MAP_PLAYER_SIZE))
	{
		j = -(MAP_PLAYER_SIZE);
		while (j < (MAP_PLAYER_SIZE))
		{
			if (x >= 0 && (x + i) / scale < WIN_WIDTH
				&& y >= 0 && (y + j) / scale < WIN_HEIGTH)
				((int *)game->addr)[(y + j) / scale * (game->line_length >> 2)
					+ (x + i) / scale] = RED;
			j++;
		}
		i++;
	}
}

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
			if (x * MAP_BOX_SIZE + i > 0 && y * MAP_BOX_SIZE + j > 0
				&& x * MAP_BOX_SIZE + i < WIN_WIDTH
				&& y * MAP_BOX_SIZE + j < WIN_HEIGTH)
			{
				if (i == 0 || i == MAP_BOX_SIZE || j == 0 || j == MAP_BOX_SIZE)
					ft_mlx_pixel_put(game, x * MAP_BOX_SIZE + i,
						y * MAP_BOX_SIZE + j, BLACK);
				else
					ft_mlx_pixel_put(game, x * MAP_BOX_SIZE + i,
						y * MAP_BOX_SIZE + j, color);
			}
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
		if ((y + 1) * MAP_BOX_SIZE > WIN_HEIGTH)
			break ;
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				ft_draw_square(game, x + game->map_x, y + game->map_y, SILVER);
			else if (map[y][x] == '0')
				ft_draw_square(game, x + game->map_x, y + game->map_y, WHITE);
			x++;
		}
		y++;
	}
}

void	ft_draw_fov(t_data *game, int x, int y)
{
	static const int		scale = BOX_SIZE / MAP_BOX_SIZE;
	t_line					line;
	float					angle;

	angle = game->degree;
	angle -= M_PI / 6;
	while (angle <= game->degree + M_PI / 6)
	{
		ft_add_x_line(&line, x + game->map_x * BOX_SIZE, WIN_WIDTH / 2, angle);
		ft_add_y_line(&line, y + game->map_y * BOX_SIZE, WIN_HEIGTH / 2, angle);
		ft_draw_ray(game, &line, GREEN, scale);
		angle += M_PI / WIN_WIDTH;
	}
	ft_add_x_line(&line, x + game->map_x * BOX_SIZE, WIN_WIDTH / 2,
		game->degree);
	ft_add_y_line(&line, y + game->map_y * BOX_SIZE, WIN_HEIGTH / 2,
		game->degree);
	ft_draw_ray(game, &line, BLUE, scale);
}
