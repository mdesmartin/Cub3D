/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:02:01 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/19 13:39:54 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_data	*ft_game_init(void)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	if (!game)
	{
		perror("Memory allocation failed for t_data game");
		exit (12);
	}
	return (game);
}
