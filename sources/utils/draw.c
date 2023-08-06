/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:29:42 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/06 15:20:01 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_refresh_img(t_data *game)
{
	game->img = mlx_new_image(game->mlx_ptr, 1280, 720);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	ft_draw_floor_ceiling(game);
	if (game->show_map == 1)
	{
		ft_draw_map(game, game->map);
		ft_render_player(game, game->x_player, game->y_player);
		ft_draw_fov(game);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	if (game->img)
		mlx_destroy_image(game->mlx_ptr, game->img);
}

void	ft_mlx_pixel_put(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_add_x_line(t_line *line, int x0, int x1, float degree)
{
	line->x0 = x0;
	line->x1 = x1;
	line->x_f = cosf(degree) * 1000 + x0 ;
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
	line->y_f = sinf(degree) * 1000 + y0;
	line->dy = line->y_f - (float) line->y0;
	if (line->dy < 0)
		line->dy *= -1;
	line->dy *= -1;
	if ((float) line->y0 < line->y_f)
		line->sy = 1;
	else
		line->sy = -1;
}

void	ft_draw_fov(t_data *game)
{
	float	degree;
	int		i;

	i = 0;
	degree = game->degree;
	degree += M_PI / 6;
	while (degree >= game->degree - M_PI / 6)
	{
		ft_add_x_line(&game->line, game->x_player, WIN_WIDTH / 2, degree);
		ft_add_y_line(&game->line, game->y_player, WIN_HEIGTH / 2, degree);
		ft_draw_ray(game, &game->line, GREEN);
		degree -= M_PI / WIN_WIDTH;
	}
	ft_add_x_line(&game->line, game->x_player, WIN_WIDTH / 2, game->degree);
	ft_add_y_line(&game->line, game->y_player, WIN_HEIGTH / 2, game->degree);
	ft_draw_ray(game, &game->line, BLUE);
}
