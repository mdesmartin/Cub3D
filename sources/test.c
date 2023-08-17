/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:50:15 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/17 10:55:43 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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

t_point	ft_wall_collision_test(t_data *game, t_line *line)
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

void	ft_add_x_line_test(t_line *line, int x0, int x1, float degree)
{
	line->x0 = x0;
	line->x1 = x1;
	line->x_f = cosf(degree) * WIN_WIDTH + x0 ;
	line->dx = line->x_f - (float) line->x0;
	if (line->dx < 0)
		line->dx *= -1;
	if ((float) line->x0 < line->x_f)
		line->sx = 1;
	else
		line->sx = -1;
}

void	ft_add_y_line_test(t_line *line, int y0, int y1, float degree)
{
	line->y0 = y0;
	line->y1 = y1;
	line->y_f = sinf(degree) * WIN_WIDTH + y0;
	line->dy = line->y_f - (float) line->y0;
	if (line->dy < 0)
		line->dy *= -1;
	line->dy *= -1;
	if ((float) line->y0 < line->y_f)
		line->sy = 1;
	else
		line->sy = -1;
}

void	ft_test(t_data *game)
{
	t_point	point;
	t_line	line;
	float	angle;

	angle = game->degree;
	angle -= M_PI / 6;
	while (angle <= game->degree + M_PI / 6)
	{
		ft_add_x_line_test(&line, game->player_x, WIN_WIDTH / 2, angle);
		ft_add_y_line_test(&line, game->player_y, WIN_HEIGTH / 2, angle);
		point = ft_wall_collision_test(game, &line);
		angle += M_PI / (3 * WIN_WIDTH);
	}
}
