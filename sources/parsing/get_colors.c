/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:01:05 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/16 15:26:31 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	get_color_int(char *rgb, int *i)
{
	int				start;

	start = *i;
	while (rgb[*i] && rgb[*i] != ',')
		*i += 1;
	if (rgb[*i])
		rgb[*i] = '\0';
	return (atoi(&rgb[start]));
}

int	get_rgb(char *rgb)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	r = get_color_int(rgb, &i);
	if (r > 255 || r < 0)
		return (ft_dprintf(2, "Error\nColor 'r' has exceeded the range [0,255]\n"), -1);
	i++;
	g = get_color_int(rgb, &i);
	if (g > 255 || g < 0)
		return (ft_dprintf(2, "Error\nColor 'g' has exceeded the range [0,255]\n"), -1);
	i++;
	b = get_color_int(rgb, &i);
	if (b > 255 || b < 0)
		return (ft_dprintf(2, "Error\nColor 'b' has exceeded the range [0,255]\n"), -1);
	return (r << 16 | g << 8 | b);
}

int	get_color_code(t_parsing *parsed, char *element, int size, int *color)
{
	int	i;
	int	j;

	i = 0;
	while (parsed->description[i])
	{
		j = 0;
		while (is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j] != '\n'
			&& !ft_strncmp(&parsed->description[i][j], element, size))
		{
			j += size;
			*color = get_rgb(&parsed->description[i][j]);
			if (*color == -1)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}
