/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:35:35 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/31 15:36:26 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_key(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_quit(game);
	// if (ft_check_position(key, game) == 0 && game->result != 'W')
	// {
	// 	if (key == 119 || key == 65362)
	// 		ft_move(game, &game->player_y, -1, 'L');
	// 	if (key == 115 || key == 65364)
	// 		ft_move(game, &game->player_y, 1, 'R');
	// 	if (key == 97 || key == 65361)
	// 		ft_move(game, &game->player_x, -1, 'L');
	// 	if (key == 100 || key == 65363)
	// 		ft_move(game, &game->player_x, 1, 'R');
	// }
	return (0);
}
