/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:20:29 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/09 17:21:20 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ft_player_start_init(t_data *game)
{
	game->player_x = game->player_x * BOX_SIZE + BOX_SIZE / 2;
	game->player_y = game->player_y * BOX_SIZE + BOX_SIZE / 2;
	if (game->player_direction == 'N')
		game->degree = -M_PI_2;
	else if (game->player_direction == 'S')
		game->degree = M_PI_2;
	else if (game->player_direction == 'E')
		game->degree = 0;
	else if (game->player_direction == 'W')
		game->degree = M_PI;
}

int	get_player(t_data *game, t_parsing *parsed)
{
	int	y;
	int	x;

	y = parsed->map_north;
	while (y <= parsed->map_south)
	{
		x = parsed->map_west;
		while (x <= parsed->map_east && parsed->description[y][x])
		{
			if (is_cardinal_point(parsed->description[y][x]))
			{
				game->player_direction = parsed->description[y][x];
				game->player_x = x - parsed->map_west;
				game->player_y = y - parsed->map_north;
				parsed->description[y][x] = '0';
				ft_player_start_init(game);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
