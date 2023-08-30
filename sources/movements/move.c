/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:27:59 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/29 16:02:19 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	rotate(t_data *game, float rotation)
{
	game->degree += rotation;
	if (game->degree >= M_PI * 2)
		game->degree -= M_PI * 2;
	else if (game->degree <= M_PI * -2)
		game->degree += M_PI * 2;
}

static void	map_refresh(t_data *game)
{
	if (game->move.i)
		game->map_y--;
	if (game->move.j)
		game->map_x--;
	if (game->move.k)
		game->map_y++;
	if (game->move.l)
		game->map_x++;
}

int	game_refresh(t_data *game)
{
	mouse_move(game);
	if (game->move.w || game->move.up)
		move(game, 1, 0);
	if (game->move.s || game->move.down)
		move(game, -1, 0);
	if (game->move.a)
		move(game, 0, 1);
	if (game->move.d)
		move(game, 0, -1);
	if (game->move.left || game->move.mouse_left)
		rotate(game, -(M_PI / 60));
	if (game->move.right || game->move.mouse_right)
		rotate(game, M_PI / 60);
	if (game->show_map == 1)
		map_refresh(game);
	return (0);
}
