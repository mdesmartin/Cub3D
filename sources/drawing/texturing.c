/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:41:25 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/28 17:10:35 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	get_color(t_display_line line, int i)
{
	u_int32_t	*pixel_tab;
	u_int32_t	x;
	u_int32_t	y;
	int			color;

	pixel_tab = (u_int32_t *)line.wall->data;
	x = line.wall->width * line.x_wall;
	y = ((line.wall->height * i) / line.wall_line_height * line.wall->width);
	if ((line.wall->width * line.wall->height) < (int)(x + y) || x < 0 || y < 0)
		color = 0;
	else
		color = pixel_tab[x + y];
	return (color);
}

static void	init_face(t_data *game, t_display_line *line)
{
	if (line->face == 'N')
		line->wall = game->north;
	else if (line->face == 'S')
		line->wall = game->south;
	else if (line->face == 'E')
		line->wall = game->east;
	else if (line->face == 'W')
		line->wall = game->west;
}

void	print_line(t_data *game, t_display_line line)
{
	int		y_win_max;
	int		y_win_min;
	int		i;

	i = 0;
	init_face(game, &line);
	y_win_max = (WIN_HEIGTH >> 1) + (line.wall_line_height >> 1);
	y_win_min = (WIN_HEIGTH >> 1) - (line.wall_line_height >> 1) + 1;
	while (y_win_max >= y_win_min)
	{
		if (line.x_win > 0 && line.x_win < WIN_WIDTH
			&& y_win_min > 0 && y_win_min < WIN_HEIGTH)
			((int *)game->addr)[y_win_min * (game->line_length >> 2)
				+ line.x_win] = get_color(line, i);
		i++;
		y_win_min++;
	}
}
