/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:01:05 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/16 16:23:05 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	color_error(int r, int g, int b)
{
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		ft_dprintf(2, "Error\nA Color has exceeded the range [0,255]\n");
		return (1);
	}
	return (0);
}

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
	i++;
	g = get_color_int(rgb, &i);
	i++;
	b = get_color_int(rgb, &i);
	if (color_error(r, g, b))
		return (-1);
	else
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
