/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:35:25 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/17 15:51:39 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	ft_wall_face(float x, float y)
{
	if (((int) y % BOX_SIZE == 0 && (int)(x + 1) % BOX_SIZE != 0)
		|| ((int) y % BOX_SIZE == 0 && (int) x % BOX_SIZE == 0))
		return ('N');
	else if (((int)(x + 1) % BOX_SIZE == 0 && (int)(y + 1) % BOX_SIZE != 0)
		|| ((int)(x + 1) % BOX_SIZE == 0 && (int) y % BOX_SIZE == 0))
		return ('E');
	else if (((int)(y + 1) % BOX_SIZE == 0 && (int) x % BOX_SIZE != 0)
		|| ((int)(y + 1) % BOX_SIZE == 0 && (int)(x + 1) % BOX_SIZE == 0))
		return ('S');
	else
		return ('W');
}

float	ft_wall_position(t_point point, char face)
{
	float	res;

	if (point.x % BOX_SIZE == 0 || (point.x + 1) % BOX_SIZE == 0)
	{
		while (point.y > BOX_SIZE - 1)
			point.y -= BOX_SIZE;
		res = (float)point.y / BOX_SIZE;
	}
	else
	{
		while (point.x > BOX_SIZE - 1)
			point.x -= BOX_SIZE;
		res = (float)point.x / BOX_SIZE;
	}
	if (face == 'N' || face == 'E')
		res = 1 - res;
	return (res);
}

static t_point	ft_save_collision_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

static int	ft_ray_collision(t_data *game, int new_x, int new_y)
{
	new_x = new_x / BOX_SIZE;
	new_y = new_y / BOX_SIZE;
	if (game->map[new_y][new_x] == '1')
		return (1);
	return (0);
}

t_point	ft_wall_collision(t_data *game, t_line *line)
{
	float	e2;

	line->e = line->dx + line->dy;
	while (ft_ray_collision(game, line->x0, line->y0) == 0)
	{
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
	return (ft_save_collision_point(line->x0, line->y0));
}
