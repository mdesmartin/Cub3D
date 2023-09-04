/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_description.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:58:35 by mdesmart          #+#    #+#             */
/*   Updated: 2023/09/04 15:58:41 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	something_after_map(t_parsing *parsed)
{
	int	i;
	int	j;

	i = parsed->map_south + 1;
	while (parsed->description[i])
	{
		j = 0;
		while (parsed->description[i][j])
		{
			if (!is_whitespace_or_end(parsed->description[i][j]))
				return (ft_dprintf(2, "Error\nInvalid char after map\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_duplicated(t_parsing *parsed, char *element, int size, int i)
{
	int	j;

	while (parsed->description[i] && i < parsed->map_north + 1)
	{
		j = 0;
		while (parsed->description[i][j]
			&& is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j]
			&& !ft_strncmp(&parsed->description[i][j], element, size))
			return (ft_dprintf(2, "Error\nDuplicated "), 1);
		i++;
	}
	return (0);
}

static int	find_element(t_parsing *parsed, char *element, int size)
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
			&& !ft_strncmp(&parsed->description[i][j], element, size))
		{
			if ((is_duplicated(parsed, element, size, i + 1)))
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_duplicated(t_parsing *parsed)
{
	if (!find_element(parsed, "NO", 2))
		return (ft_dprintf(2, "'NO' element\n"), 1);
	else if (!find_element(parsed, "SO", 2))
		return (ft_dprintf(2, "'SO' element\n"), 1);
	else if (!find_element(parsed, "EA", 2))
		return (ft_dprintf(2, "'EA' element\n"), 1);
	else if (!find_element(parsed, "WE", 2))
		return (ft_dprintf(2, "'WE' element\n"), 1);
	else if (!find_element(parsed, "F", 1))
		return (ft_dprintf(2, "'F' element\n"), 1);
	else if (!find_element(parsed, "C", 1))
		return (ft_dprintf(2, "'C' element\n"), 1);
	else
		return (0);
}
