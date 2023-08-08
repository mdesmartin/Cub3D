/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:27 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/08 21:53:56 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	check_symbols(t_parsing *parsed)
{
	int	y;
	int	x;
	int	wall;

	wall = 0;
	y = parsed->map_north;
	while (y <= parsed->map_south)
	{
		x = parsed->map_west;
		while (x <= parsed->map_east && parsed->description[y][x])
		{
			if (!is_map_symbol(parsed->description[y][x]) && parsed->description[y][x] != ' ' && parsed->description[y][x] != '\n')
				return (1);
			if (parsed->description[y][x] == '1' && !wall)
				wall = 1;
			x++;
		}
		y++;
	}
	if (wall)
		return (0);
	else
		return (2);
}

int	borders_whitespace(t_parsing *parsed, int y, int x)
{
	if (y == parsed->map_north || y == parsed->map_south 
		|| x == parsed->map_east || x == parsed->map_west)
		return (1);
	else if (is_whitespace(parsed->description[y - 1][x - 1]) 
		|| is_whitespace(parsed->description[y - 1][x + 1])
		|| is_whitespace(parsed->description[y + 1][x - 1])
		|| is_whitespace(parsed->description[y + 1][x + 1])
		|| is_whitespace(parsed->description[y - 1][x])
		|| is_whitespace(parsed->description[y + 1][x])
		|| is_whitespace(parsed->description[y][x - 1]) 
		|| is_whitespace(parsed->description[y][x + 1]))
		return (1);
	else
		return (0);
}

int	check_walls(t_parsing *parsed)
{
	int	y;
	int	x;
	char symbol;

	y = parsed->map_north;
	while (y <= parsed->map_south)
	{
		x = parsed->map_west;
		while (x <= parsed->map_east && parsed->description[y][x])
		{
			symbol = parsed->description[y][x];
			if (symbol != '1' && !is_whitespace(symbol) && symbol != '\n'
				&& borders_whitespace(parsed, y, x))
			{
				printf("missing wall x:%d y:%d\n", x, y);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_player(t_parsing *parsed)
{
	int	y;
	int	x;
	int	symbol;

	symbol = 0;
	y = parsed->map_north;
	while (y <= parsed->map_south)
	{
		x = parsed->map_west;
		while (x <= parsed->map_east && parsed->description[y][x])
		{
			if (parsed->description[y][x] == 'N' || parsed->description[y][x] == 'S'
			|| parsed->description[y][x] == 'E' || parsed->description[y][x] == 'W')
				symbol += 1;
			x++;
		}
		y++;
	}
	if (!symbol)
		return (1);
	else if (symbol > 1)
		return (2);
	return (0);
}

int	check_map(t_parsing *parsed)
{
	get_map_cardinal_limits(parsed);
	if (check_symbols(parsed) == 1)
		return (ft_dprintf(2, "Error\nForbidden symbol(s) in map\n"), 1);
	else if (check_symbols(parsed) == 2)
		return (ft_dprintf(2, "Error\nMap need to be limited by walls\n"), 1);
	else if (check_walls(parsed))
		return (ft_dprintf(2, "Error\nMissing wall(s) to border map\n"), 1);
	else if (check_player(parsed) == 1)
		return (ft_dprintf(2, "Error\nOne player needed (N, S, E, W)\n"), 1);
	else if (check_player(parsed) == 2)
		return (ft_dprintf(2, "Error\nOnly one player needed\n"), 1);
	else
		return (0);
}