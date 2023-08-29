/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:07:01 by mvogel            #+#    #+#             */
/*   Updated: 2023/08/29 13:18:06 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	get_mouse(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!mlx_mouse_get_pos(game->mlx_ptr, game->win_ptr, &x, &y))
		return (0);
	if (y < WIN_HEIGTH && y > 0)
	{
		if (x < (WIN_WIDTH / 3) && x > 0)
			return (1);
		else if (x > ((WIN_WIDTH / 3) * 2) && x < WIN_WIDTH)
			return (2);
	}
	return (0);
}

void	mouse_move(t_data *game)
{
	int	mouse;

	mouse = get_mouse(game);
	if (mouse == 1)
		game->move.mouse_left = 1;
	else if (mouse == 2)
		game->move.mouse_right = 1;
	else
	{
		game->move.mouse_left = 0;
		game->move.mouse_right = 0;
	}
}
