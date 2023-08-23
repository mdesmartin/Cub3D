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

static int	get_original_size(char **av)
{
	int		fd;
	int		size;
	char	buff;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nFailed to open map\n"), -1);
	size = 1;
	while (read(fd, &buff, 1))
		size++;
	if (size < 2)
		return (close(fd), ft_dprintf(2, "Error\nMap is empty\n"), -1);
	close(fd);
	return (size);
}

static int	get_new_size(char **tab)
{
	int	size;
	int	i;

	size = 1;
	i = 0;
	while (tab[i])
	{
		size += ft_strlen(tab[i]);
		i++;
	}
	return (size);
}

static int	get_number_line(char **av)
{
	char	*line;
	int		nb_line;
	int		fd;

	nb_line = 1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nFailed to open map\n"), 0);
	line = get_next_line(fd);
	if (!line)
		return (ft_dprintf(2, "Error\nFailed to gnl map\n"), 0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			nb_line += 1;
	}
	close(fd);
	if (nb_line == 1)
		return (ft_dprintf(2, "Error\nFailed to gnl map\n"), 0);
	return (nb_line);
}

static int	init_map(t_parsing *parsed, char **av)
{
	int	nb_line;

	nb_line = get_number_line(av);
	if (!nb_line)
		return (1);
	parsed->description = ft_calloc(nb_line + 1, sizeof(char *));
	if (!parsed->description)
		return (ft_dprintf(2, "Error\nFailed to calloc in init_map\n"), 1);
	return (0);
}

int	get_description(t_parsing *parsed, char **av)
{
	int	i;
	int	original_size;
	int	new_size;
	int	fd;

	i = 0;
	original_size = get_original_size(av);
	if (original_size == -1)
		return (1);
	if (init_map(parsed, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nFailed to open map\n"), 1);
	parsed->description[i] = get_next_line(fd);
	while (parsed->description[i])
	{
		i++;
		parsed->description[i] = get_next_line(fd);
	}
	new_size = get_new_size(parsed->description);
	if (new_size != original_size)
		return (ft_dprintf(2, "Error\nFailed to copy map\n"), 1);
	close(fd);
	return (0);
}
