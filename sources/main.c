/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:45 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/02 14:43:44 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_first_img(t_data *game)
{
	game->img = mlx_new_image(game->mlx_ptr, 1280, 720);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	ft_render_player(game, game->x_player, game->y_player);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	if (game->img)
		mlx_destroy_image(game->mlx_ptr, game->img);

}

int	main(int ac, char **av)
{
	t_data	*game;

	ft_check_arg(ac, av);
	game = ft_game_init();
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1280, 720, "cub3D");
	ft_load_textures(game);
	ft_first_img(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, ft_key, game);
	mlx_hook(game->win_ptr, 17, 0L, ft_quit, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
