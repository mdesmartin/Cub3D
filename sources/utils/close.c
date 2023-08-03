/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:02:27 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/03 14:08:53 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

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
	if (game->path_north)
		free(game->path_north);
	if (game->path_south)
		free(game->path_south);
	if (game->path_east)
		free(game->path_east);
	if (game->path_west)
		free(game->path_west);
}

int	ft_quit(t_data *game)
{
	ft_free_textures(game);
	ft_free_tab(game->map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	game->mlx_ptr = NULL;
	free(game);
	exit(0);
}

void	ft_error(t_data *game, char *str)
{
	perror(str);
	ft_quit(game);
}
