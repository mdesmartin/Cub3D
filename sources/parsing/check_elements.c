/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:34:55 by mvogel            #+#    #+#             */
/*   Updated: 2023/08/08 22:41:10 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	find_element(t_parsing *parsed, char *element, int size)
{
	int	i;
	int	j;

	i = 0;
	while (parsed->description[i])
	{
		j = 0;
		while (parsed->description[i][j] && is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j] && !ft_strncmp(&parsed->description[i][j], element, size))
		{
			if (i + 1 > parsed->map_north)
				parsed->map_north = i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_elements(t_parsing *parsed)
{
	if (!find_element(parsed, "NO", 2))
		return (ft_dprintf(2, "Error\nMissing 'NO' element\n"), 1);
	else if (!find_element(parsed, "SO", 2))
		return (ft_dprintf(2, "Error\nMissing 'SO' element\n"), 1);
	else if (!find_element(parsed, "EA", 2))
		return (ft_dprintf(2, "Error\nMissing 'EA' element\n"), 1);
	else if (!find_element(parsed, "WE", 2))
		return (ft_dprintf(2, "Error\nMissing 'WE' element\n"), 1);
	else if (!find_element(parsed, "F", 1))
		return (ft_dprintf(1, "Error\nMissing 'F' element\n"), 1);
	else if (!find_element(parsed, "C", 1))
		return (ft_dprintf(1, "Error\nMissing 'C' element\n"), 1);
	else
		return (0);
}
