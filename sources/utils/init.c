/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:02:01 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/30 12:59:25 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ft_check_texture_file(t_data *game, char *texture_file)
{
	char	*msg;
	int		fd;

	fd = open(texture_file, O_RDONLY, 0644);
	if (fd == -1)
	{
		msg = ft_strjoin("Error\nBad texture file: ", texture_file);
		if (!msg)
		{
			ft_error(game, "Error\nError message creation failed");
			return ;
		}
		perror(msg);
		free(msg);
		ft_quit(game);
	}
	close(fd);
}

static void	ft_check_textures(t_data *game)
{
	ft_check_texture_file(game, game->path_north);
	ft_check_texture_file(game, game->path_south);
	ft_check_texture_file(game, game->path_east);
	ft_check_texture_file(game, game->path_west);
}

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
	game->screen_dst = WIN_WIDTH / (2 * tanf(FOV_2));
	return (game);
}
