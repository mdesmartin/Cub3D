/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:02:01 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/27 17:37:26 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	ft_check_texture_file(t_data *game, char *texture_file)
{
	char	*msg;
	int		fd;

	fd = open(texture_file, O_RDONLY, 0644);
	if (fd == -1)
	{
		msg = ft_strjoin("Error: ", texture_file);
		if (!msg)
		{
			ft_error(game, "Error when creating error message");
			return (12);
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

static void	ft_load_textures(t_data *game)
{
	int	box_size;

	box_size = 64;
	ft_check_textures(game);
	game->north = mlx_xpm_file_to_image(game->mlx_ptr,
			game->path_north, box_size, box_size);
	game->south = mlx_xpm_file_to_image(game->mlx_ptr,
			game->path_south, box_size, box_size);
	game->east = mlx_xpm_file_to_image(game->mlx_ptr,
			game->path_east, box_size, box_size);
	game->west = mlx_xpm_file_to_image(game->mlx_ptr,
			game->path_west, box_size, box_size);
	if (!game->north || !game->south || !game->east || !game->west)
	{
		ft_dprintf(2, "Xpm convertion failed !");
		ft_quit(game);
	}
}

t_data	*ft_game_init(void)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	if (!game)
	{
		perror("Memory allocation failed for t_data game");
		exit (12);
	}
	return (game);
}
