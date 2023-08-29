/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:14:33 by mvogel            #+#    #+#             */
/*   Updated: 2023/08/23 10:40:26 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	init_parsed(t_parsing **parsed)
{
	*parsed = ft_calloc(1, sizeof(t_parsing));
	if (!(*parsed))
		return (ft_dprintf(2, \
		"Error\nMemory allocation failed for t_parsing parsed\n"), 1);
	(*parsed)->map_north = 0;
	(*parsed)->map_east = 0;
	(*parsed)->map_south = 0;
	(*parsed)->map_west = 0;
	return (0);
}

int	parsing(t_data	*game, char **av)
{
	t_parsing	*parsed;

	parsed = NULL;
	if (init_parsed(&parsed))
		return (1);
	if (get_description(parsed, av))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	if (check_elements(parsed))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	if (check_map(parsed))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	if (get_elements(game, parsed))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	if (get_map(game, parsed))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	ft_free_tab(parsed->description);
	free(parsed);
	return (0);
}
