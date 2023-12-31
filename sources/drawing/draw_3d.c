/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:20:36 by jmoutous          #+#    #+#             */
/*   Updated: 2023/09/05 12:50:07 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_draw_floor_ceiling(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGTH)
		{
			if (j >= 0 && j < (WIN_HEIGTH >> 1))
				((int *)game->addr)[j * (game->line_length >> 2) + i]
					= game->ceiling_color;
			else if (j >= (WIN_HEIGTH >> 1) && j < WIN_HEIGTH)
				((int *)game->addr)[j * (game->line_length >> 2) + i]
					= game->floor_color;
			j++;
		}
		i++;
	}
}

static float	ft_wall_position(float x, float y, char face)
{
	float	res;

	if (face == 'S')
		x--;
	if (face == 'E')
		y--;
	if (face == 'E' || face == 'W')
	{
		while (y > BOX_SIZE)
			y -= BOX_SIZE;
		res = y / BOX_SIZE;
	}
	else
	{
		while (x > BOX_SIZE)
			x -= BOX_SIZE;
		res = x / BOX_SIZE;
	}
	if (face == 'N' || face == 'E')
		res = 1 - res;
	return (res);
}

static void	ft_draw_wall(t_data *game, t_col_point point, int x_display)
{
	t_display_line	line;

	line.wall_line_height = game->screen_dst * BOX_SIZE / point.depth;
	line.face = point.face;
	line.x_wall = ft_wall_position(point.x, point.y, line.face);
	line.x_win = x_display;
	print_line(game, line);
}

void	ft_draw_3d(t_data *game)
{
	t_col_point	point;
	float		angle;
	int			i;

	i = 0;
	angle = game->degree;
	angle -= FOV_2;
	while (i < WIN_WIDTH)
	{
		point = ft_3d_wall_collision(game, angle);
		ft_draw_wall(game, point, i);
		angle = atanf((i + 0.0001 - WIN_WIDTH / 2) / game->screen_dst)
			+ game->degree + 0.0001;
		i++;
	}
}
