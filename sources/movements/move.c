/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:35:35 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/16 22:52:39 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ft_move(t_data *game, int forward, int strafe)
{
	ft_position_cal(game, forward, strafe);
}

static void	ft_rotate(t_data *game, float rotation)
{
	game->degree += rotation;
	if (game->degree >= M_PI * 2)
		game->degree -= M_PI * 2;
	else if (game->degree <= M_PI * -2)
		game->degree += M_PI * 2;
}

static void	ft_show_map(t_data *game)
{
	if (game->show_map == 0)
		game->show_map = 1;
	else
		game->show_map = 0;
}

static void	ft_move_map(int key, t_data *game)
{
	if (key == KEY_I)
		game->map_y-- ;
	if (key == KEY_K)
		game->map_y++ ;
	if (key == KEY_J)
		game->map_x-- ;
	if (key == KEY_L)
		game->map_x++ ;
}

int	ft_key(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_quit(game);
	else if (key == KEY_W || key == KEY_UP)
		ft_move(game, 1, 0);
	else if (key == KEY_S || key == KEY_DOWN)
		ft_move(game, -1, 0);
	else if (key == KEY_A)
		ft_move(game, 0, 1);
	else if (key == KEY_D)
		ft_move(game, 0, -1);
	else if (key == KEY_LEFT)
		ft_rotate(game, -(M_PI / 60));
	else if (key == KEY_RIGHT)
		ft_rotate(game, M_PI / 60);
	else if (key == KEY_M)
		ft_show_map(game);
	else if (game->show_map == 1)
		ft_move_map(key, game);
	return (0);
}
