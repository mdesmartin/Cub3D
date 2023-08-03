/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:14:33 by mvogel            #+#    #+#             */
/*   Updated: 2023/08/03 13:45:42 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

//what tp do when error ?

int	init_parsed(t_parsing *parsed)
{
	parsed = malloc(sizeof(t_parsing));
	if (!parsed)
		return (ft_dprintf(1, "Memory allocation failed for t_parsing parsed"), 1);
	parsed->map_north = 0;
	parsed->map_east = 0;
	parsed->map_south = 0;
	parsed->map_west = 0;
	return (0);
}

int	parsing(t_data	*game, char **av)
{
	t_parsing *parsed;

	init_parsed(parsed);
	if (get_description(parsed, av))
		return (1);
	if (check_elements(parsed))
		return (1);
	if (check_map(parsed))
		return (1);
	if (get_elements(game, parsed))
		return (1);
	if (get_map(game, parsed))
		return (1);
	ft_free_tab(parsed->description);
	return (0);
}

//estce vraoimemt sumbole puis espace emsuite ?
//strncmp
//replace errrorn exit by something
