/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:50:53 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/16 23:24:19 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	ft_ray_collision(t_data *game, int new_x, int new_y)
{
	new_x = (new_x - game->map_x * BOX_SIZE) / BOX_SIZE;
	new_y = (new_y - game->map_y * BOX_SIZE) / BOX_SIZE;
	if (game->map[new_y][new_x] == '1')
		return (1);
	return (0);
}

void	ft_draw_ray(t_data *game, t_line *line, int color, int scale)
{
	float	e2;
	int		i;

	i = 0;
	line->e = line->dx + line->dy;
	while (ft_ray_collision(game, line->x0, line->y0) == 0 && i < 3000)
	{
		if (line->x0 > 0 && line->x0 / scale < WIN_WIDTH
			&& line->y0 > 0 && line->y0 / scale < WIN_HEIGTH)
			ft_mlx_pixel_put(game, line->x0 / scale, line->y0 / scale, color);
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
		i++;
	}
}
