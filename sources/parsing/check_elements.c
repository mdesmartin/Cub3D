/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:34:55 by mvogel            #+#    #+#             */
/*   Updated: 2023/08/10 17:43:46 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	color_formated(char *str, int j)
{
	int	coma;

	coma = 0;
	while (str[j] && is_whitespace(str[j]))
		j++;
	while (str[j])
	{
		if (!ft_isdigit(str[j]) && str[j] != ','
			&& !is_whitespace_or_end(str[j]))
			return (0);
		if (str[j] == ',')
			coma += 1;
		j++;
	}
	if (coma != 2)
		return (0);
	else
		return (1);
}

int	is_empty(char *str, int j, int size)
{
	j += size;
	while (str[j] && is_whitespace(str[j]))
		j++;
	if (str[j] && str[j] != '\n')
		return (0);
	else
		return (1);
}

int	find_element(t_parsing *parsed, char *element, int size)
{
	int	i;
	int	j;

	i = 0;
	while (parsed->description[i])
	{
		j = 0;
		while (parsed->description[i][j]
			&& is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j]
			&& !ft_strncmp(&parsed->description[i][j], element, size + 1))
		{
			if (is_empty(parsed->description[i], j, size + 1))
				return (0);
			if (size == 1 && !color_formated(parsed->description[i], j + size))
				return (0);
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
	if (!find_element(parsed, "NO ", 2))
		return (ft_dprintf(2, "Error\nMissing 'NO' element\n"), 1);
	else if (!find_element(parsed, "SO ", 2))
		return (ft_dprintf(2, "Error\nMissing 'SO' element\n"), 1);
	else if (!find_element(parsed, "EA ", 2))
		return (ft_dprintf(2, "Error\nMissing 'EA' element\n"), 1);
	else if (!find_element(parsed, "WE ", 2))
		return (ft_dprintf(2, "Error\nMissing 'WE' element\n"), 1);
	else if (!find_element(parsed, "F ", 1))
		return (ft_dprintf(2, "Error\nMissing 'F' element\n"), 1);
	else if (!find_element(parsed, "C ", 1))
		return (ft_dprintf(2, "Error\nMissing 'C' element\n"), 1);
	else
		return (0);
}
