/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:35:35 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/05 16:50:07 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_render_player(t_data *game, int x, int y)
{
	int	i;
	int	j;

	i = -PLAYER_SIZE / 2;
	while (i < PLAYER_SIZE / 2)
	{
		j = -PLAYER_SIZE / 2;
		while (j < PLAYER_SIZE / 2)
		{
			if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGTH)
				ft_mlx_pixel_put(game, x + i, y + j, 0xff0000);
			j++;
		}
		i++;
	}

}

static void	ft_move(t_data *game, int forward, int strafe)
{
	ft_position_cal(game, forward, strafe);
	game->img = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	ft_draw_map(game, game->map);
	ft_render_player(game, game->x_player, game->y_player);
	ft_draw_fov(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	if (game->img)
		mlx_destroy_image(game->mlx_ptr, game->img);
}

static void	ft_rotate(t_data *game, float rotation)
{
	game->degree += rotation;
	game->img = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	ft_draw_map(game, game->map);
	ft_render_player(game, game->x_player, game->y_player);
	ft_draw_fov(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	if (game->img)
		mlx_destroy_image(game->mlx_ptr, game->img);
}

int	ft_key(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_quit(game);
	if ((key == KEY_W || key == KEY_UP))
		ft_move(game, 1, 0);
	if ((key == KEY_S || key == KEY_DOWN))
		ft_move(game, -1, 0);
	if (key == KEY_A)
		ft_move(game, 0, 1);
	if (key == KEY_D)
		ft_move(game, 0, -1);
	if (key == KEY_LEFT)
		ft_rotate(game, -(M_PI / 60));
	if (key == KEY_RIGHT)
		ft_rotate(game, M_PI / 60);
	return (0);
}

