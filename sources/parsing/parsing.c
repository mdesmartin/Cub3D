/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:14:33 by mvogel            #+#    #+#             */
/*   Updated: 2023/07/27 17:36:17 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	parsing(t_data	*game, char **av)
{
	get_description(game, av);
	check_elements(game);
	check_map(game);
	get_elements(game);
	get_map(game);
}

//estce vraoimemt sumbole puis espace emsuite ?
//strncmp
//replace errrorn exit by something
