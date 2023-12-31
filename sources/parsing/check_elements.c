/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:34:55 by mvogel            #+#    #+#             */
/*   Updated: 2023/09/05 09:20:06 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	color_formated(char *str, int j)
{
	int	coma;
	int	digit;

	coma = 0;
	digit = 0;
	while (str[j] && is_whitespace(str[j]))
		j++;
	while (str[j] && !is_whitespace_or_end(str[j]))
	{
		if (!ft_isdigit(str[j]) && str[j] != ','
			&& str[j] != '\n')
			return (ft_dprintf(2, "Error\nInvalid format for "), 0);
		if (!digit && ft_isdigit(str[j]) && (is_whitespace_or_end(str[j - 1])))
			digit += 1;
		else if (digit > 0 && ft_isdigit(str[j]) && str[j - 1] == ',')
			digit += 1;
		if (str[j] == ',')
			coma += 1;
		j++;
	}
	if (coma != 2 || digit != 3)
		return (ft_dprintf(2, "Error\nInvalid format for "), 0);
	else
		return (1);
}

static int	is_empty(char *str, int j, int size)
{
	j += size;
	while (str[j] && is_whitespace(str[j]))
		j++;
	if (str[j] && str[j] != '\n')
		return (0);
	else
		return (ft_dprintf(2, "Error\nMissing "), 1);
}

int	nothing_after(char *str, int i)
{
	while (str[i] && is_whitespace(str[i]))
		i++;
	while (str[i] && !is_whitespace_or_end(str[i]))
		i++;
	while (str[i] && is_whitespace(str[i]))
		i++;
	if (str[i] && str[i] == '\n')
		return (1);
	else
		return (ft_dprintf(2, "Error\nInvalid format for "), 0);
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
			if ((is_empty(parsed->description[i], j, size)) || (size == 1 && \
			!color_formated(parsed->description[i], j + size)) || \
			!nothing_after(parsed->description[i], j + size))
				return (0);
			if (i + 1 > parsed->map_north)
				parsed->map_north = i + 1;
			return (1);
		}
		i++;
	}
	return (ft_dprintf(2, "Error\nMissing "), 0);
}

int	check_elements(t_parsing *parsed)
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
