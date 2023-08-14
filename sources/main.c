/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:45 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/11 17:36:56 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int ac, char **av)
{
	t_data	*game;

	ft_check_arg(ac, av);
	game = ft_game_init();
	if (parsing(game, av))
		return (free_main(game), 1);
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1280, 720, "cub3D");
	ft_load_textures(game);
	ft_refresh_img(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, ft_key, game);
	mlx_hook(game->win_ptr, 17, 0L, ft_quit, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
