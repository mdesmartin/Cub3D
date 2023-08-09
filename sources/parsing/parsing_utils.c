/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:35:25 by mvogel            #+#    #+#             */
/*   Updated: 2023/08/09 12:06:07 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

int	is_map_symbol(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W' || c == '0' || c == '1')
		return (1);
	else
		return (0);
}

// void	*ft_free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i] != NULL)
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	if (tab)
// 		free(tab);
// 	return (NULL);
// }