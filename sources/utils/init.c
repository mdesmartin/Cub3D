/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:02:01 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/31 11:56:14 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_load_textures(t_data *game)
{
	int	box_size;

	box_size = BOX_SIZE;
	ft_check_textures(game);
	game->north = mlx_xpm_file_to_image(game->mlx_ptr,
			game->path_north, &box_size, &box_size);
	game->south = mlx_xpm_file_to_image(game->mlx_ptr,
			game->path_south, &box_size, &box_size);
	game->east = mlx_xpm_file_to_image(game->mlx_ptr,
			game->path_east, &box_size, &box_size);
	game->west = mlx_xpm_file_to_image(game->mlx_ptr,
			game->path_west, &box_size, &box_size);
	if (!game->north || !game->south || !game->east || !game->west)
	{
		ft_dprintf(2, "Error\nXpm convertion failed !");
		ft_quit(game);
	}
	ft_map_size(game);
}

static void	ft_game_init_null(t_data *game)
{
	game->img = NULL;
	game->addr = NULL;
	game->show_map = 0;
	game->degree = 0;
	game->map = NULL;
	game->north = NULL;
	game->south = NULL;
	game->east = NULL;
	game->west = NULL;
	game->path_north = NULL;
	game->path_south = NULL;
	game->path_east = NULL;
	game->path_west = NULL;
	game->map_x = 0;
	game->map_y = 0;
	game->map_height = 0;
	game->map_width = 0;
}

void	game_init_move(t_data	*game)
{
	game->move.w = 0;
	game->move.a = 0;
	game->move.s = 0;
	game->move.d = 0;
	game->move.up = 0;
	game->move.down = 0;
	game->move.left = 0;
	game->move.right = 0;
	game->move.mouse_left = 0;
	game->move.mouse_right = 0;
	game->move.i = 0;
	game->move.j = 0;
	game->move.k = 0;
	game->move.l = 0;
}

t_data	*ft_game_init(void)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	if (!game)
	{
		perror("Error\nMemory allocation failed for t_data game");
		exit (12);
	}
	ft_game_init_null(game);
	game_init_move(game);
	game->screen_dst = WIN_WIDTH / (2 * tanf(FOV_2));
	return (game);
}
