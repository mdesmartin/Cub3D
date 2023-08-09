/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:12:36 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/09 14:08:42 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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
