/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:14:33 by mvogel            #+#    #+#             */
/*   Updated: 2023/08/08 15:46:38 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

//what tp do when error ?

int	init_parsed(t_parsing **parsed)
{
	*parsed = ft_calloc(1, sizeof(t_parsing));
	if (!parsed)
		return (ft_dprintf(1, "Memory allocation failed for t_parsing parsed"), 1);
	(*parsed)->map_north = 0;
	(*parsed)->map_east = 0;
	(*parsed)->map_south = 0;
	(*parsed)->map_west = OPEN_MAX;
	return (0);
}

void	print_tab(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
	printf("\n");
}

int	parsing(t_data	*game, char **av)
{
	t_parsing *parsed;

	parsed = NULL;
	if (init_parsed(&parsed))
		return (free(parsed), 1);
	if (get_description(parsed, av))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	print_tab(parsed->description);//
	if (check_elements(parsed))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	if (check_map(parsed))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	if (get_elements(game, parsed))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	if (get_map(game, parsed))
		return (ft_free_tab(parsed->description), free(parsed), 1);
	ft_free_tab(parsed->description);
	return (0);
}

//estce vraoimemt sumbole puis espace emsuite ?
//strncmp
//replace errrorn exit by something
