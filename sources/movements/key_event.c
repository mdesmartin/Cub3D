/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:01:10 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/29 16:55:11 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	press_key_map(int key, t_data *game)
{
	if (key == KEY_M)
	{
		if (game->show_map == 0)
			game->show_map = 1;
		else
			game->show_map = 0;
	}
	else if (key == KEY_N)
	{
		game->map_x = (game->player_x * -1 + WIN_WIDTH) / BOX_SIZE;
		game->map_y = (game->player_y * -1 + WIN_HEIGTH) / BOX_SIZE;
	}
	else if (key == KEY_I)
		game->move.i = 1;
	else if (key == KEY_J)
		game->move.j = 1;
	else if (key == KEY_K)
		game->move.k = 1;
	else if (key == KEY_L)
		game->move.l = 1;
}

int	press_key(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_quit(game);
	else if (key == KEY_W)
		game->move.w = 1;
	else if (key == KEY_A)
		game->move.a = 1;
	else if (key == KEY_S)
		game->move.s = 1;
	else if (key == KEY_D)
		game->move.d = 1;
	else if (key == KEY_UP)
		game->move.up = 1;
	else if (key == KEY_DOWN)
		game->move.down = 1;
	else if (key == KEY_LEFT)
		game->move.left = 1;
	else if (key == KEY_RIGHT)
		game->move.right = 1;
	else
		press_key_map(key, game);
	return (0);
}

static void	release_key_map(int key, t_data *game)
{
	if (key == KEY_I)
		game->move.i = 0;
	if (key == KEY_J)
		game->move.j = 0;
	if (key == KEY_K)
		game->move.k = 0;
	if (key == KEY_L)
		game->move.l = 0;
}

int	release_key(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_quit(game);
	else if (key == KEY_W)
		game->move.w = 0;
	else if (key == KEY_A)
		game->move.a = 0;
	else if (key == KEY_S)
		game->move.s = 0;
	else if (key == KEY_D)
		game->move.d = 0;
	else if (key == KEY_UP)
		game->move.up = 0;
	else if (key == KEY_DOWN)
		game->move.down = 0;
	else if (key == KEY_LEFT)
		game->move.left = 0;
	else if (key == KEY_RIGHT)
		game->move.right = 0;
	else
		release_key_map(key, game);
	return (0);
}
