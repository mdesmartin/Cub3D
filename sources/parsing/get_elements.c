/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:20 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/03 14:53:29 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	get_path(t_parsing *parsed, char *element, int size, char *path)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (parsed->description[i])
	{
		j = 0;
		while (is_whitespace(parsed->description[i][j++]))
		if (ft_strncmp(&parsed->description[i][j], element, size))
		{
			j += size;
			while (is_whitespace(parsed->description[i][j++]))
			len = j;
			while (!is_whitespace(parsed->description[i][len++]))//alphanum?
			len -= j;
			path = ft_substr(parsed->description[i], j, len);
			if (!path)
				return (ft_dprintf(2, "Error\nMalloc failed in get_path\n"), 0);//va falloir free en cascade avant si cest alloué
		}
		i++;
	}
	return (1);
}

int	get_rgb(char *rgb, int *color)
{
	char	*color_code;
	int		a;
	int		i;
	int		j;

	color_code = NULL;
	a = 0;
	i = 0;
	while (a < 3)
	{
		j = 0;
		while (rgb[i] && rgb[i] != ',' && is_whitespace(rgb[i]))
		{
			color_code[j] = rgb[i];
			j++;
			i++;
		}
		color[a] = ft_atoi(color_code);
		color_code = NULL;
		i++;
		a++;
	}
	return (1);
}

int	get_color(t_parsing *parsed, char *element, int size, int *color)
{
	int	i;
	int	j;

	i = 0;
	while (parsed->description[i])
	{
		j = 0;
		while (is_whitespace(parsed->description[i][j++]))
		if (ft_strncmp(&parsed->description[i][j], element, size))
		{
			j += size;
			while (is_whitespace(parsed->description[i][j++]));
			if (get_rgb(&parsed->description[i][j], color))
				return (1);
		}
		i++;
	}
	return (0);
}

int	get_elements(t_data *game, t_parsing *parsed)
{
	if (!get_path(parsed,  "NO", 2, game->path_north))
		return (1);
	if (!get_path(parsed,  "EA", 2, game->path_east))
		return (1);
	if (!get_path(parsed,  "SO", 2, game->path_south))
		return (1);
	if (!get_path(parsed,  "WE", 2, game->path_west))
		return (1);
	if (!get_color(parsed,  "F", 1, game->floor_color))
		return (1);
	if (!get_color(parsed,  "C", 1, game->ceiling_color))
		return (1);
}
