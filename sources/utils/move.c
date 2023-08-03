/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:35:35 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/03 11:26:21 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_render_player(t_data *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			if (x >= 0 && x < 1280 && y >= 0 && y < 720)
				ft_mlx_pixel_put(game, x + i, y + j, 0xff0000);
			j++;
		}
		i++;
	}

}

static void	ft_move(t_data *game, int *pos, int direction, float rotation)
{
	*pos += 10 * direction;
	game->degree += rotation;
	game->img = mlx_new_image(game->mlx_ptr, 1280, 720);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	ft_render_player(game, game->x_player, game->y_player);
	ft_draw_line(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	if (game->img)
		mlx_destroy_image(game->mlx_ptr, game->img);
}

int	ft_key(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_quit(game);
	if ((key == KEY_W || key == KEY_UP) && game->y_player > 0)
		ft_move(game, &game->y_player, -1, 0);
	if ((key == KEY_S || key == KEY_DOWN) && game->y_player + PLAYER_SIZE < 720)
		ft_move(game, &game->y_player, 1, 0);
	if (key == KEY_LEFT && game->x_player > 0)
		ft_move(game, &game->x_player, -1, 0);
	if (key == KEY_RIGHT && game->x_player + PLAYER_SIZE < 1280)
		ft_move(game, &game->x_player, 1, 0);
	if (key == KEY_A)
		ft_move(game, &game->x_player, 0, -(M_PI / 90));
	if (key == KEY_D)
		ft_move(game, &game->x_player, 0, M_PI / 90);
	return (0);
}

// protect rotation