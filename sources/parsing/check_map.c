/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:27 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/18 10:54:40 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	check_symbols(t_parsing *parsed)
{
	int	y;
	int	x;

	y = parsed->map_north;
	while (y <= parsed->map_south)
	{
		x = parsed->map_west;
		while (x <= parsed->map_east && parsed->description[y][x])
		{
			if (!is_map_symbol(parsed->description[y][x])
				&& parsed->description[y][x] != ' '
				&& parsed->description[y][x] != '\n')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	borders_whitespace_or_end(t_parsing *parsed, int y, int x)
{
	if (y == parsed->map_north || y == parsed->map_south
		|| x == parsed->map_east || x == parsed->map_west)
		return (1);
	else if (is_whitespace_or_end(parsed->description[y - 1][x])
		|| is_whitespace_or_end(parsed->description[y + 1][x])
		|| is_whitespace_or_end(parsed->description[y][x - 1])
		|| is_whitespace_or_end(parsed->description[y][x + 1]))
		return (1);
	else
		return (0);
}

int	check_walls(t_parsing *parsed)
{
	int		y;
	int		x;
	char	symbol;

	y = parsed->map_north;
	while (y <= parsed->map_south)
	{
		x = parsed->map_west;
		while (x <= parsed->map_east && parsed->description[y][x])
		{
			symbol = parsed->description[y][x];
			if (symbol != '1' && !is_whitespace(symbol) && symbol != '\n'
				&& borders_whitespace_or_end(parsed, y, x))
				return (1);
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
			if (is_cardinal_point(parsed->description[y][x]))
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
	if (get_map_cardinal_limits(parsed))
		return (1);
	if (check_symbols(parsed) == 1)
		return (ft_dprintf(2, "Error\nForbidden symbol(s) in map\n"), 1);
	else if (check_walls(parsed))
		return (ft_dprintf(2, "Error\nMissing wall(s) to border map\n"), 1);
	else if (check_player(parsed) == 1)
		return (ft_dprintf(2, "Error\nOne player needed (N, S, E, W)\n"), 1);
	else if (check_player(parsed) == 2)
		return (ft_dprintf(2, "Error\nOnly one player needed\n"), 1);
	else
		return (0);
}
