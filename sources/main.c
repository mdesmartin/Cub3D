/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:45 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/08 13:56:36 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	parsing_test(t_data	*game)
{
	// print_tab(game->map);
	printf("path_north : %s\n", game->path_north);
	printf("path_south : %s\n", game->path_south);
	printf("path_east : %s\n", game->path_east);
	printf("path_west : %s\n", game->path_west);

	printf("floor_color :%d\n", game->floor_color);
	printf("floor_color :%d\n", game->ceiling_color);

	printf("player_x : %d\nplayer_y : %d\n", game->player_x, game->player_y);
	printf("player_direction : %c\n", game->player_direction);
}

void	free_main(t_data	*game)
{
	if (game->map)
		ft_free_tab(game->map);
	if (game)
		free(game);
}

int	main(int ac, char **av)//finir dessayer de print
{
	t_data	*game;

	ft_check_arg(ac, av);
	game = ft_game_init();
	if (parsing(game, av))
		return (free_main(game), 1);
	// parsing_test(game);//
	// game->mlx_ptr = mlx_init();
	// game->win_ptr = mlx_new_window(game->mlx_ptr, 1280, 720, "cub3D");
	// mlx_hook(game->win_ptr, 17, 0L, ft_quit, game);
	// mlx_loop(game->mlx_ptr);
	return (0);
}
