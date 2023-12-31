/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_cardinal_limits.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:42:13 by mdesmart          #+#    #+#             */
/*   Updated: 2023/09/04 15:40:36 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	get_map_north(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_north;
	while (parsed->description[i])
	{
		j = 0;
		while (parsed->description[i][j]
			&& is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j]
			&& is_map_symbol(parsed->description[i][j]))
		{
			parsed->map_north = i;
			return ;
		}
		i++;
	}
}

static void	get_map_south(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_north;
	while (parsed->description[i])
	{
		j = 0;
		while (parsed->description[i][j]
			&& is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j] && parsed->description[i][j] == '\n')
		{
			parsed->map_south = i - 1;
			return ;
		}
		i++;
	}
	parsed->map_south = i - 1;
}

static void	get_map_east(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_north;
	while (i <= parsed->map_south)
	{
		j = parsed->map_west;
		while (parsed->description[i][j]
			&& (is_map_symbol(parsed->description[i][j])
			|| is_whitespace(parsed->description[i][j])))
			j++;
		while (j > 0 && (!is_map_symbol(parsed->description[i][j])))
			j--;
		if (j > parsed->map_east)
			parsed->map_east = j;
		i++;
	}
}

static void	get_map_west(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_north;
	j = 0;
	while (parsed->description[i][j]
		&& is_whitespace(parsed->description[i][j]))
		j++;
	parsed->map_west = j;
	i++;
	while (i <= parsed->map_south)
	{
		j = 0;
		while (parsed->description[i][j]
			&& is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j]
			&& is_map_symbol(parsed->description[i][j]))
		{
			if (j < parsed->map_west)
				parsed->map_west = j;
		}
		i++;
	}
}

int	get_map_cardinal_limits(t_parsing *parsed)
{
	get_map_north(parsed);
	get_map_south(parsed);
	if (check_duplicated(parsed) || something_after_map(parsed))
		return (1);
	if (parsed->map_north >= parsed->map_south)
		return (ft_dprintf(2, "Error\nMissing map\n"), 1);
	get_map_west(parsed);
	get_map_east(parsed);
	if ((unsigned int)(parsed->map_south - parsed->map_north) >
		(UINT_MAX * BOX_SIZE) || (unsigned int)(parsed->map_east -
		parsed->map_west) > (UINT_MAX * BOX_SIZE))
		return (ft_dprintf(2, "Error\nMap too laaaaaaarge\n"), 1);
	return (0);
}
