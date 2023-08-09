/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:20 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/09 17:26:30 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	move_on_space(char **tab, int i, int *j)
{
	while (tab[i][*j] && is_whitespace(tab[i][*j]))
		*j += 1;
}

void	get_len(char **tab, int i, int *j, int *len)
{
	*len = *j;
	while (tab[i][*len] && !is_whitespace(tab[i][*len]))
		*len += 1;
	*len -= 1;
	*len -= *j;
}

int	get_path(t_parsing *parsed, char *element, int size, char **path)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (parsed->description[i])
	{
		j = 0;
		move_on_space(parsed->description, i, &j);
		if (parsed->description[i][j] != '\n'
			&& !ft_strncmp(&parsed->description[i][j], element, size))
		{
			j += size;
			move_on_space(parsed->description, i, &j);
			get_len(parsed->description, i, &j, &len);
			*path = ft_substr(parsed->description[i], j, len);
			if (!path)
				return (ft_dprintf(2, "Error\nMalloc failed in get_path\n"), 0);
			return (1);
		}
		else
			i++;
	}
	return (0);
}

int	get_elements(t_data *game, t_parsing *parsed)
{
	if (!get_path(parsed, "NO", 2, &game->path_north))
		return (1);
	else if (!get_path(parsed, "EA", 2, &game->path_east))
		return (1);
	else if (!get_path(parsed, "SO", 2, &game->path_south))
		return (1);
	else if (!get_path(parsed, "WE", 2, &game->path_west))
		return (1);
	else if (!get_color_code(parsed, "F", 1, &game->floor_color))
		return (1);
	else if (!get_color_code(parsed, "C", 1, &game->ceiling_color))
		return (1);
	else if (!get_player(game, parsed))
		return (1);
	else
		return (0);
}
