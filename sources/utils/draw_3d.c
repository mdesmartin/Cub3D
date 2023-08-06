/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:20:36 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/06 14:38:27 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ft_draw_floor_ceiling(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGTH)
		{
			if (j >= 0 && j < WIN_HEIGTH / 2)
				ft_mlx_pixel_put(game, i, j, game->ceiling_color);
			else if (j >= WIN_HEIGTH / 2 && j < WIN_HEIGTH)
				ft_mlx_pixel_put(game, i, j, game->floor_color);
			j++;
		}
		i++;
	}

}

void	ft_draw_3d(t_data *game)
{
	ft_draw_floor_ceiling(game);
}
