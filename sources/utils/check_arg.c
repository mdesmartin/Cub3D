/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:26:01 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/31 15:08:44 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ft_check_map_name(char *directory)
{
	char	*map_name;

	if (ft_strrchr(directory, '/') != 0)
	{
		map_name = ft_strrchr(directory, '/');
		map_name++;
	}
	else
		map_name = directory;
	if (ft_strlen(map_name) < 5
		|| ft_strncmp(&map_name[ft_strlen(map_name) - 4], ".cub", 4) != 0)
	{
		ft_printf("Map's name must be at least 1 character follow by .cub!\n");
		exit (1);
	}
}

void	ft_check_arg(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("Error\nPlease execute cube3D follow by a map!\n");
		exit (1);
	}
	else if (ac > 2)
	{
		ft_printf("Error\nPlease execute cube3D follow by only one map!\n");
		exit (1);
	}
	else
		ft_check_map_name(av[1]);
}
