/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:02:27 by jmoutous          #+#    #+#             */
/*   Updated: 2023/07/31 15:36:26 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ft_free_textures(t_data *game)
{
	if (game->north)
		mlx_destroy_image(game->mlx_ptr, game->north);
	if (game->south)
		mlx_destroy_image(game->mlx_ptr, game->south);
	if (game->east)
		mlx_destroy_image(game->mlx_ptr, game->east);
	if (game->west)
		mlx_destroy_image(game->mlx_ptr, game->west);
}

int	ft_quit(t_data *game)
{
	ft_free_textures(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	game->mlx_ptr = NULL;
	exit(0);
}

void	ft_error(t_data *game, char *str)
{
	perror(str);
	ft_quit(game);
}
