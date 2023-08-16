/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:41:25 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/16 16:42:18 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	get_color(t_display_line line, int i)
{
	u_int32_t	*pixel_tab;
	u_int32_t	x;
	u_int32_t	y;
	int			color;

	pixel_tab = (u_int32_t *)line.wall->data;
	x = line.wall->width * line.x_wall;
	y = ((line.wall->height * i) / line.wall_line_height * line.wall->width);
	if ((line.wall->width * line.wall->height) < (int)(x + y))
		color = 0;
	else
		color = pixel_tab[x + y];
	return (color);
}

void	init_face(t_data *game, t_display_line *line)
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
	int		y_win;
	int		y_min_win;
	int		i;
	int		color;

	i = 0;
	init_face(game, &line);
	y_win = (WIN_HEIGTH / 2) + (line.wall_line_height / 2);
	y_min_win = (WIN_HEIGTH / 2) - (line.wall_line_height / 2);
	while (y_win >= y_min_win)
	{
		if (line.x_win > 0 && line.x_win < WIN_WIDTH
			&& y_min_win > 0 && y_min_win < WIN_HEIGTH)
		{
			color = get_color(line, i);
			ft_mlx_pixel_put(game, line.x_win, y_min_win, color);
		}
		i++;
		y_min_win++;
	}
}
