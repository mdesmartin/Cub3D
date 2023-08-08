/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:02:01 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/08 13:53:16 by jmoutous         ###   ########lyon.fr   */
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
		msg = ft_strjoin("Error: ", texture_file);
		if (!msg)
		{
			ft_error(game, "Error when creating error message");
			return ;
		}
		perror(msg);
		free(msg);
		ft_quit(game);
	}
	close(fd);
}
// Test function used because the final texture are not yet implemented

static void	ft_check_textures(t_data *game)
{
game->path_north = ft_strdup("./textures/test.xpm");
game->path_south = ft_strdup("./textures/test.xpm");
game->path_east = ft_strdup("./textures/test.xpm");
game->path_west = ft_strdup("./textures/test.xpm");
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
		ft_dprintf(2, "Xpm convertion failed !");
		ft_quit(game);
	}
}

static void	ft_player_start_direction(t_data *game)
{
	if (game->direction == 'N')
		game->degree = -M_PI_2;
	else if (game->direction == 'S')
		game->degree = M_PI_2;
	else if (game->direction == 'E')
		game->degree = 0;
	else if (game->direction == 'W')
		game->degree = M_PI;
}

static void	ft_map_gen(t_data *game)
{
	game->map = ft_calloc(10, sizeof(char *));
	game->map[0] = ft_strdup("111111111111111");
	game->map[1] = ft_strdup("100000000000001");
	game->map[2] = ft_strdup("101110111011101");
	game->map[3] = ft_strdup("101010101010101");
	game->map[4] = ft_strdup("100000000000001");
	game->map[5] = ft_strdup("101010101010101");
	game->map[6] = ft_strdup("101010101010101");
	game->map[7] = ft_strdup("100000000000001");
	game->map[8] = ft_strdup("111111111111111");
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
	ft_map_gen(game);
game->direction = 'S';
	ft_player_start_direction(game);
game->x_player = 3 * BOX_SIZE + BOX_SIZE / 2;
game->y_player = 4 * BOX_SIZE + BOX_SIZE / 2;
game->img = NULL;
game->addr = NULL;
game->show_map = 0;
game->floor_color = OLIVE;
game->ceiling_color = NAVY;
	return (game);
}
