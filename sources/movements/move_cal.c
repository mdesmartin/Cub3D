/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:57:08 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/29 16:02:13 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ft_calculate_line(t_line *new_pos, int direction)
{
	float	e2;
	int		i;

	i = 0;
	new_pos->e = new_pos->dx + new_pos->dy;
	while (i < STEP_LENGTH)
	{
		e2 = 2 * new_pos->e;
		if (e2 >= new_pos->dy)
		{
			new_pos->e += new_pos->dy;
			new_pos->x0 += new_pos->sx * direction;
		}
		if (e2 <= new_pos->dx)
		{
			new_pos->e += new_pos->dx;
			new_pos->y0 += new_pos->sy * direction;
		}
		i++;
	}
}

void	move(t_data *game, int forward, int strafe)
{
	t_line	new_pos;

	if (forward != 0)
	{
		ft_add_x_line(&new_pos, game->player_x, WIN_WIDTH, game->degree);
		ft_add_y_line(&new_pos, game->player_y, WIN_HEIGTH, game->degree);
		ft_calculate_line(&new_pos, forward);
	}
	else if (strafe != 0)
	{
		ft_add_x_line(&new_pos, game->player_x, WIN_WIDTH,
			game->degree - M_PI_2);
		ft_add_y_line(&new_pos, game->player_y, WIN_HEIGTH,
			game->degree - M_PI_2);
		ft_calculate_line(&new_pos, strafe);
	}
	if (ft_check_collision(game, new_pos.x0, game->player_y) == 0)
		game->player_x = new_pos.x0;
	if (ft_check_collision(game, game->player_x, new_pos.y0) == 0)
		game->player_y = new_pos.y0;
}
