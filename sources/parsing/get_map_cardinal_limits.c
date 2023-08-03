/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_cardinal_points.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:42:13 by mdesmart          #+#    #+#             */
/*   Updated: 2023/07/31 17:15:28 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	get_map_north(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_north;
	while (parsed->description[i])
	{
		j = 0;
		while (parsed->description[i][j] && is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j] && is_map_symbol(parsed->description[i][j]))
		{
			parsed->map_north = i;
			return ;
		}
		i++;
	}
}

void	get_map_south(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_north;
	while (parsed->description[i])
	{
		j = 0;
		while (parsed->description[i][j] && is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j] && is_map_symbol(parsed->description[i][j]))
			i++;
		else
			parsed->map_south = i - 1;
	}
}

void	get_west_west(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_north;
	while (parsed->description[i])
	{
		j = 0;
		while (parsed->description[i][j] && is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j] && is_map_symbol(parsed->description[i][j]))
		{
			if (j < parsed->map_west)
				parsed->map_west = j;
		}
		i++;
	}
}

void	get_east_south(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_north;
	while (parsed->description[i])
	{
		j = parsed->map_west;
		while (parsed->description[i][j] && (is_map_symbol(parsed->description[i][j]) || is_whitespace(parsed->description[i][j])))
			j++;
		if (j - 1 > parsed->map_east)
			parsed->map_east = j - 1;
		i++;
	}
}

void	get_map_cardinal_limits(t_parsing *parsed)
{
	get_map_north(parsed);
	get_map_south(parsed);
	get_map_west(parsed);
	get_map_east(parsed);
}