/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:16 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/03 13:42:46 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	get_map(t_data *game, t_parsing *parsed)
{
	char	**map;
	int		i;
	int		y;
	int		nb_lines;
	int		nb_columns;

	i = 0;
	y = 0;
	nb_lines = parsed->map_south - parsed->map_north + 1;
	nb_columns = parsed->map_east - parsed->map_west + 1;
	map = ft_calloc(nb_lines + 1, sizeof(char *));
	if (!map)
		return (ft_free_tab(map), ft_dprintf(2, "Error\nMalloc failed in get_map\n"), 1);
	y = parsed->map_north;
	while (i <= nb_lines)
	{
		map[i] = ft_substr(parsed->description[y], parsed->map_west, nb_columns);
		y++;
		i++;
	}
	map[i] = NULL;
	game->map = map;
	return (0);
}

//partons du principe quon ne gere pas les tab dans la carte mais uniquement les space