/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:20 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/08 22:05:08 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	get_path(t_parsing *parsed, char *element, int size, char **path)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (parsed->description[i])
	{
		j = 0;
		while (is_whitespace(parsed->description[i][j]))
			j++;
		if (parsed->description[i][j] != '\n' && !ft_strncmp(&parsed->description[i][j], element, size))
		{
			j += size;
			while (parsed->description[i][j] && is_whitespace(parsed->description[i][j]))
				j++;
			len = j;
			while (parsed->description[i][len] && !is_whitespace(parsed->description[i][len]))
				len++;
			len--;
			len -= j;
			*path = ft_substr(parsed->description[i], j, len);
			if (!path)
				return (ft_dprintf(2, "Error\nMalloc failed in get_path\n"), 0);//va falloir free en cascade avant si cest allou
			else
				return (1);
		}
		else
			i++;
	}
	return (0);
}

// int	get_color_int(char *rgb, int *i)
// {
// 	char			*color_code;
// 	unsigned char	color;
// 	int				j;

// 	color_code = NULL;
// 	j = 0;
// 	while (rgb[*i] && rgb[*i] != ',' && !is_whitespace(rgb[*i]))
// 	{
// 		color_code[j] = rgb[*i];
// 		j++;
// 		i++;
// 	}
// 	i++;
// 	color = (unsigned char)color_code;
// 	return (atoi((char*)color));
// }

// int	get_rgb(char *rgb)
// {
// 	int	i;
// 	int	r;
// 	int g;
// 	int b;

// 	i = 0;
// 	r = get_color_int(rgb, &i);
// 	g = get_color_int(rgb, &i);
// 	b = get_color_int(rgb, &i);
// 	return (r << 16 || g << 8 || b);//check again
// }

// //récupérer couleurs caster dans unsigned char puis transformer en un int avec calcul rgb (voir internet)

// int	get_color_code(t_parsing *parsed, char *element, int size, int *color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (parsed->description[i])
// 	{
// 		j = 0;
// 		while (is_whitespace(parsed->description[i][j]))
// 			j++;
// 		if (parsed->description[i][j] != '\n' && !ft_strncmp(&parsed->description[i][j], element, size))
// 		{
// 			j += size;
// 			while (is_whitespace(parsed->description[i][j]))
// 				j++;
// 			*color = get_rgb(&parsed->description[i][j]);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int get_player(t_data *game, t_parsing *parsed)
{
	int	y;
	int	x;

	y = parsed->map_north;
	while (y <= parsed->map_south)
	{
		x = parsed->map_west;
		while (x <= parsed->map_east && parsed->description[y][x])
		{
			if (parsed->description[y][x] == 'N' || parsed->description[y][x] == 'S'
			|| parsed->description[y][x] == 'E' || parsed->description[y][x] == 'W')
			{
				game->player_direction = parsed->description[y][x];
				game->player_x = x - parsed->map_west;
				game->player_y = y - parsed->map_north; 
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	get_elements(t_data *game, t_parsing *parsed)
{
	if (!get_path(parsed,  "NO", 2, &game->path_north))
		return (1);
	else if (!get_path(parsed,  "EA", 2, &game->path_east))
		return (1);
	else if (!get_path(parsed,  "SO", 2, &game->path_south))
		return (1);
	else if (!get_path(parsed,  "WE", 2, &game->path_west))
		return (1);
	// printf("NO:%s\nEA:%s\nSO:%s\nWE:%s\n", game->path_north, game->path_east, game->path_south, game->path_west);
	// else if (!get_color_code(parsed,  "F", 1, &game->floor_color))
	// 	return (1);
	// else if (!get_color_code(parsed,  "C", 1, &game->ceiling_color))
	// 	return (1);
	else if (!get_player(game, parsed))
		return (1);
	else
		return (0);
}
