/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:27:59 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/29 09:37:41 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	mouse_move(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!mlx_mouse_get_pos(game->mlx_ptr, game->win_ptr, &x, &y))
	{
		game->move.left = 0;
		game->move.right = 0;
	}
	if (x < (WIN_WIDTH / 3) && x > 0 && y < WIN_HEIGTH && y > 0)
		game->move.left = 1;
	else if (x > ((WIN_WIDTH / 3) * 2) && x < WIN_WIDTH 
		&& y < WIN_HEIGTH && y > 0)
		game->move.right = 1;
	else
	{
		game->move.left = 0;
		game->move.right = 0;
	}
}

static void	move(t_data *game, int forward, int strafe)
{
	ft_position_cal(game, forward, strafe);
}

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
	if (game->move.left)
		rotate(game, -(M_PI / 60));
	if (game->move.right)
		rotate(game, M_PI / 60);
	if (game->show_map == 1)
		map_refresh(game);
	return (0);
}
