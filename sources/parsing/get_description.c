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

#include "../../includes/cube3d.h"

int	get_map_size(char **av)
{
	int		fd;
	int		size;
	char	buff;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nFailed to open map\n"), 1);
	size = 1;
	while (read(fd, &buff, 1))
		size++;
	if (size < 2)
		return (close(fd), ft_dprintf(2, "Error\nMap is empty\n"), 1);
	close(fd);
	return (size);
}

void	get_description(t_parsing *parsed, char **av)
{
	char	*line;
	int		fd;
	int		size;

	size = get_map_size(av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nFailed to open map\n"), 1);
	line = (char *)ft_calloc(size, sizeof(char));
	if (!line)
		return (ft_dprintf(2, "Error\nFailed to malloc map\n"), 1);
	if (read(fd, line, size) == -1)
	{
		close(fd);
		free(line);
		ft_dprintf(2, "Error\nFailed to read map\n");
		return (1);
	}
	close(fd);
	parsed->description = ft_split(line, '\n');
	free(line);
	if (!parsed->description)
		return (ft_dprintf(2, "Error\nFailed to split map\n"), 1);
}
