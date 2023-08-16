/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:35:35 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/16 13:59:51 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ft_move(t_data *game, int forward, int strafe)
{
	ft_position_cal(game, forward, strafe);
	// ft_refresh_img(game);
}

static void	ft_rotate(t_data *game, float rotation)
{
	game->degree += rotation;
	if (game->degree >= M_PI * 2)
		game->degree -= M_PI * 2;
	else if (game->degree <= M_PI * -2)
		game->degree += M_PI * 2;
	// ft_refresh_img(game);
}

static void	ft_show_map(t_data *game)
{
	if (game->show_map == 0)
		game->show_map = 1;
	else
		game->show_map = 0;
	// ft_refresh_img(game);
}

int	ft_key(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_quit(game);
	if ((key == KEY_W || key == KEY_UP))
		ft_move(game, 1, 0);
	if ((key == KEY_S || key == KEY_DOWN))
		ft_move(game, -1, 0);
	if (key == KEY_A)
		ft_move(game, 0, 1);
	if (key == KEY_D)
		ft_move(game, 0, -1);
	if (key == KEY_LEFT)
		ft_rotate(game, -(M_PI / 60));
	if (key == KEY_RIGHT)
		ft_rotate(game, M_PI / 60);
	if (key == KEY_M)
		ft_show_map(game);
	return (0);
}

