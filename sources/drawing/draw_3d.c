/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:20:36 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/09 13:05:03 by jmoutous         ###   ########lyon.fr   */
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

static t_point	ft_save_collision_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

static t_point	ft_wall_distance(t_data *game, t_line *line)
{
	float	e2;

	line->e = line->dx + line->dy;
	while (ft_ray_collision(game, line->x0, line->y0) == 0)
	{
		if (line->x0 > 0 && line->x0 < WIN_WIDTH
			&& line->y0 > 0 && line->y0 < WIN_HEIGTH)
			;
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
	return (ft_save_collision_point(line->x0, line->y0));
}


void	ft_draw_wall(t_data *game, t_point point, int x_pixel)
{
	float	wall_heigth;
	float	distance;
	int		y;

	distance = sqrtf(pow((point.x - game->player_x), 2)
			+ pow((point.y - game->player_y), 2));
	wall_heigth = ((WIN_HEIGTH / 2) * 350.7) / distance;
	y = (int)(WIN_HEIGTH / 2 - wall_heigth / 2);
	while (y <= (int)(WIN_HEIGTH / 2 + wall_heigth / 2))
	{
		if (x_pixel > 0 && x_pixel < WIN_WIDTH && y > 0 && y < WIN_HEIGTH)
		{
			if (point.x % 80 == 0 && point.y % 80 == 0)
				ft_mlx_pixel_put(game, x_pixel, y, BLACK);
			else
				ft_mlx_pixel_put(game, x_pixel, y, LIME);
		}
		y++;
	}
}

void	ft_draw_3d(t_data *game)
{
	float	degree;
	t_point	point;
	int		i;

	i = 0;
	degree = game->degree;
	degree -= M_PI / 6;
	while (degree <= game->degree + M_PI / 6)
	{
		ft_add_x_line(&game->line, game->player_x, WIN_WIDTH / 2, degree);
		ft_add_y_line(&game->line, game->player_y, WIN_HEIGTH / 2, degree);
		point = ft_wall_distance(game, &game->line);
		ft_draw_wall(game, point, i);
		degree += M_PI / (3 * WIN_WIDTH);
		i++;
	}
}
