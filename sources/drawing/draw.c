/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:29:42 by jmoutous          #+#    #+#             */
/*   Updated: 2023/09/05 12:17:44 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_refresh_img(t_data *game)
{
	game_refresh(game);
	game->img = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	if (!game->img)
		ft_error(game, "Error\nmlx_new_image() failed\n");
	game->addr = NULL;
	if (!game->addr)
	{
		mlx_destroy_image(game->mlx_ptr, game->img);
		ft_error(game, "Error\nmlx_get_data_addr() failed\n");
	}
	ft_draw_floor_ceiling(game);
	ft_draw_3d(game);
	if (game->show_map == 1)
		ft_draw_map(game, game->map);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	if (game->img)
		mlx_destroy_image(game->mlx_ptr, game->img);
	return (0);
}

void	ft_mlx_pixel_put(t_data *game, int x, int y, int color)
{
	((int *)game->addr)[y * (game->line_length >> 2) + x] = color;
}

void	ft_add_x_line(t_line *line, int x0, int x1, float degree)
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

void	ft_add_y_line(t_line *line, int y0, int y1, float degree)
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
