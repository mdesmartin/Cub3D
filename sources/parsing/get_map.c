/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:16 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/10 17:32:21 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	error_free(char **tab, char *message)
{
	ft_free_tab(tab);
	ft_dprintf(2, message);
	return (1);
}

char	*fill_line(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s[start] && s[start] != '\n' && len)
	{
		str[i] = s[start];
		start++;
		i++;
		len--;
	}
	while (len)
	{
		str[i] = ' ';
		i++;
		len--;
	}
	return (str);
}

int	get_map(t_data *game, t_parsing *parsed)
{
	char	**map;
	int		i;
	int		y;
	int		nb_lines;
	int		nb_columns;

	i = 0;
	nb_lines = parsed->map_south - parsed->map_north + 1;
	nb_columns = parsed->map_east - parsed->map_west + 1;
	map = ft_calloc(nb_lines + 1, sizeof(char *));
	if (!map)
		return (error_free(map, "Error\nMalloc failed in get_map\n"));
	y = parsed->map_north;
	while (i < nb_lines)
	{
		map[i] = fill_line(parsed->description[y], \
			parsed->map_west, nb_columns);
		if (!map[i])
			return (error_free(map, "Error\nMalloc failed in get_map\n"));
		y++;
		i++;
	}
	map[i] = NULL;
	game->map = map;
	return (0);
}
