/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:50:53 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/29 18:11:41 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_ray_length(int x_start, int y_start, int x_r, int y_r)
{
	double	ray_length;

	ray_length = sqrt(pow(x_r - x_start, 2) + pow(y_r - y_start, 2));
	return ((int) ray_length);
}

void	ft_increment_ray(t_line *line)
{
	float	e2;

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

void	ft_draw_ray(t_data *game, t_line *line, int color, int scale)
{
	int		x_start;
	int		y_start;

	x_start = line->x0;
	y_start = line->y0;
	line->e = line->dx + line->dy;
	while (ft_ray_collision(game, line->x0, line->y0) == 0
		&& ft_ray_length(x_start, y_start, line->x0, line->y0) < 1000)
	{
		if (line->x0 > 0 && line->x0 / scale < WIN_WIDTH
			&& line->y0 > 0 && line->y0 / scale < WIN_HEIGTH)
			((int *)game->addr)[line->y0 / scale * (game->line_length >> 2)
				+ line->x0 / scale] = color;
		ft_increment_ray(line);
	}
}
