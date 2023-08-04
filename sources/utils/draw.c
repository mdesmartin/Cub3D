/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:29:42 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/04 14:26:41 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_mlx_pixel_put(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_add_x_line(t_data *game, t_line *line, int x0, int x1)
{
	line->x0 = x0;
	line->x1 = x1;
	line->x_f = cosf(game->degree) * 1000 + game->x_player ;
	line->dx = line->x_f - (float) line->x0;
	if (line->dx < 0)
		line->dx *= -1;
	if ((float) line->x0 < line->x_f)
		line->sx = 1;
	else
		line->sx = -1;
}

void	ft_add_y_line(t_data *game, t_line *line, int y0, int y1)
{
	line->y0 = y0;
	line->y1 = y1;
	line->y_f = sinf(game->degree) * 1000 + game->y_player;
	line->dy = line->y_f - (float) line->y0;
	if (line->dy < 0)
		line->dy *= -1;
	line->dy *= -1;
	if ((float) line->y0 < line->y_f)
		line->sy = 1;
	else
		line->sy = -1;
}

void	ft_calculate_line(t_data *game, t_line *line, int color)
{
	float	e2;
	int		i;

	i = 0;
	line->e = line->dx + line->dy;
	while (i < 100)
	{
		if (line->x0 > 0 && line->x0 < 1280 && line->y0 > 0 && line->y0 < 720)
			ft_mlx_pixel_put(game, line->x0, line->y0, color);
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

void	ft_draw_fov(t_data *game)
{
	ft_add_x_line(game, &game->line, game->x_player, 1280 / 2);
	ft_add_y_line(game, &game->line, game->y_player, 720 / 2);
	ft_draw_ray(game, &game->line, GREEN);
	game->degree += M_PI / 6;
	ft_add_x_line(game, &game->line, game->x_player, 1280 / 2);
	ft_add_y_line(game, &game->line, game->y_player, 720 / 2);
	ft_draw_ray(game, &game->line, BLUE);
	game->degree -= M_PI / 3;
	ft_add_x_line(game, &game->line, game->x_player, 1280 / 2);
	ft_add_y_line(game, &game->line, game->y_player, 720 / 2);
	ft_draw_ray(game, &game->line, BLUE);
	game->degree += M_PI / 6;
}
