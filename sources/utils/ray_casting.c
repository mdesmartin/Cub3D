/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:50:53 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/08 13:29:39 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_ray_collision(t_data *game, int new_x, int new_y)
{
	int	new_y_w;
	int	new_y_e;
	int	new_x_n;
	int	new_x_s;

	new_y_w = (new_y - 1) / BOX_SIZE;
	new_y_e = new_y / BOX_SIZE;
	new_x_n = new_x / BOX_SIZE;
	new_x_s = (new_x - 1) / BOX_SIZE;
	if (game->map[new_y_w][new_x_n] == '1'
		|| game->map[new_y_e][new_x_n] == '1'
		|| game->map[new_y_w][new_x_s] == '1'
		|| game->map[new_y_e][new_x_s] == '1')
		return (1);
	return (0);
}

void	ft_draw_ray(t_data *game, t_line *line, int color)
{
	float	e2;

	line->e = line->dx + line->dy;
	while (ft_ray_collision(game, line->x0, line->y0) == 0)
	{
		if (line->x0 > 0 && line->x0 < WIN_WIDTH
			&& line->y0 > 0 && line->y0 < WIN_HEIGTH)
			ft_mlx_pixel_put(game, line->x0, line->y0, color);
		else
			break ;
		e2 = 2 * line->e;
		if (e2 >= line->dy)
		{
			line->e += line->dy;
			line->x0 += line->sx;
		}
		if (e2 <= line->dx)
		{
			line->e += line->dx;
			line->y0 += line->sy;
		}
	}
}
