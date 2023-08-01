/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:35:35 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/31 17:45:50 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_render_player(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			ft_mlx_pixel_put(game, game->x_player + i,
				game->y_player + j, -65536);
			j++;
		}
		i++;
	}

}

static void	ft_move(t_data *game, int *pos, int direction)
{
	*pos += 10 * direction;
	game->img = mlx_new_image(game->mlx_ptr, 1280, 720);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	ft_render_player(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	if (game->img)
		mlx_destroy_image(game->mlx_ptr, game->img);
}

int	ft_key(int key, t_data *game)
{
	if (key == KEY_ESC)
		ft_quit(game);
	if (key == KEY_W || key == KEY_UP)
		ft_move(game, &game->y_player, -1);
	if (key == KEY_S || key == KEY_DOWN)
		ft_move(game, &game->y_player, 1);
	if (key == KEY_A || key == KEY_LEFT)
		ft_move(game, &game->x_player, -1);
	if (key == KEY_D || key == KEY_RIGHT)
		ft_move(game, &game->x_player, 1);
	return (0);
}
 