/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:45 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/14 17:37:47 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	print_tab(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("-------\n");
}

void	main_parsing_test(t_data	*game)
{
	printf("MAIN TESTS\n-------\n");
	print_tab(game->map);
	printf("path_north :%s\n", game->path_north);
	printf("path_south :%s\n", game->path_south);
	printf("path_east :%s\n", game->path_east);
	printf("path_west :%s\n-------\n", game->path_west);

	printf("floor_color :%d\n", game->floor_color);
	printf("floor_color :%d\n-------\n", game->ceiling_color);

	printf("player_x :%d\nplayer_y :%d\n", game->player_x, game->player_y);
	printf("player_direction :%c\n", game->player_direction);
}

void	free_main(t_data	*game)
{
	if (game->map)
		ft_free_tab(game->map);
	if (game->path_north)
		free(game->path_north);
	if (game->path_south)
		free(game->path_south);
	if (game->path_east)
		free(game->path_east);
	if (game->path_west)
		free(game->path_west);

	if (game)
		free(game);
}

int	main(int ac, char **av)
{
	t_data	*game;

	ft_check_arg(ac, av);
	game = ft_game_init();
	if (parsing(game, av))
		return (free_main(game), 1);//ne rien faire ensuite si ca marche pas
	// main_parsing_test(game);
	game->mlx_ptr = mlx_init();
	// if (!game->mlx_ptr)
	// 	ft_quit(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			WIN_WIDTH, WIN_HEIGTH, "cub3D");
	ft_load_textures(game);
	ft_refresh_img(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, ft_key, game);
	mlx_hook(game->win_ptr, 17, 0L, ft_quit, game);
	mlx_loop(game->mlx_ptr);
	free_main(game);
	return (0);
}
