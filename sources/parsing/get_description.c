/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_description.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:32:04 by mvogel            #+#    #+#             */
/*   Updated: 2023/07/27 16:32:34 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
int	get_map_size(char **av)
{
	int		fd;
	int		size;
	char	buff;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_n_exit("Error\nFailed to open map\n");
	size = 1;
	while (read(fd, &buff, 1))
		size++;
	if (size < 2)
		return (close(fd), error_n_exit("Error\nMap is empty\n"), -1);
	close(fd);
	return (size);
}

void	get_description(t_data	*game, char **av)
{
	char	*line;
	int		fd;
	int		size;

	size = get_map_size(av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_n_exit("Error\nFailed to open map\n");
	line = (char *)ft_calloc(size, sizeof(char));
	if (!line)
		error_n_exit("Error\nFailed to malloc map\n");
	if (read(fd, line, size) == -1)
	{
		close(fd);
		free(line);
		error_n_exit("Error\nFailed to read map\n");
	}
	close(fd);
	game->description = ft_split(line, '\n');
	free(line);
	if (!game->description)
		error_n_exit("Error\nFailed to split map\n");
}
