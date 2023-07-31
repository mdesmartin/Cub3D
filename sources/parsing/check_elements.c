/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:34:55 by mvogel            #+#    #+#             */
/*   Updated: 2023/07/31 14:59:22 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
int	find_element(t_data *game, char *element, int size)
{
	int	i;
	int	j;

	i = 0;
	while (game->description[i])
	{
		j = 0;
		while (is_whitespace(game->description[i][j]))
			j++;
		if (ft_strncmp(&game->description[i][j], element, size))
			return (1);
		i++;
	}
	return (0);
}

int	check_elements(t_data	*game)
{
	if (!find_element(game, "NO", 2))
		return (ft_dprintf(2, "Error\nMissing 'NO' element\n"),1);
	if (!find_element(game, "SO", 2))
		return (ft_dprintf(2, "Error\nMissing 'SO' element\n"),1);
	if (!find_element(game, "EA", 2))
		return (ft_dprintf(2, "Error\nMissing 'EA' element\n"),1);
	if (!find_element(game, "WE", 2))
		return (ft_dprintf(2, "Error\nMissing 'WE' element\n"),1);
	if (!find_element(game, "F", 1))
		return (ft_dprintf(2, "Error\nMissing 'F' element\n"),1);
	if (!find_element(game, "C", 1))
		return (ft_dprintf(2, "Error\nMissing 'C' element\n"),1);
}
// checker chaque ligne et regarder les premiers char apres caractere et les compare, un si cest un premier element sinon inverse
