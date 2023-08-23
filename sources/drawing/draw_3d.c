/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:20:36 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/23 17:42:40 by jmoutous         ###   ########lyon.fr   */
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
			if (j >= 0 && j < WIN_HEIGTH / 2)
				ft_mlx_pixel_put(game, i, j, game->ceiling_color);
			else if (j >= WIN_HEIGTH / 2 && j < WIN_HEIGTH)
				ft_mlx_pixel_put(game, i, j, game->floor_color);
			j++;
		}
		i++;
	}
}

float	ft_wall_height(float distance)
{
	float	screen_dst;
	float	wall_heigth;

	screen_dst = WIN_HEIGTH / (2 * tanf(M_PI / 6));
	wall_heigth = (screen_dst * (WIN_HEIGTH / 3)) / distance;
	return (wall_heigth);
}

void	ft_draw_wall(t_data *game, t_col_point point, int x_display)
{
	t_display_line	line;

	line.wall_line_height = ft_wall_height(point.depth);
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
	angle -= M_PI / 6;
	while (angle <= game->degree + M_PI / 6)
	{
		point = ft_3d_wall_collision(game, angle);
		ft_draw_wall(game, point, i);
		angle += M_PI / (3 * WIN_WIDTH);
		i++;
	}
}
