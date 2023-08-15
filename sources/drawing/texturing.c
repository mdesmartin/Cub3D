/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:41:25 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/15 14:48:50 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

//protect here if overflow display white instead, how to see it overflow?
int	get_color(t_display_line line, float y_size_on_wall)
{
	u_int32_t	*pixel_tab;
	int			color;

	pixel_tab = (u_int32_t *)line.wall->data;
	color = pixel_tab[(int)((line.wall->width * line.x_wall)
			+ (line.wall->width * y_size_on_wall))];
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

void	print_line(t_data *game, t_display_line line)//the one that julien call in ft_draw_wall
{
	float	y_size_on_wall; //la taille en pixel dune ligne y du mur
	int		y_win; //la hauteur max du mur sur la grille de la win
	int		y_min_win;
	int		color;

	init_face(game, &line);
	y_size_on_wall = line.wall->height / line.wall_line_height;
	y_win = (WIN_HEIGTH / 2) + (line.wall_line_height / 2);
	y_min_win = (WIN_HEIGTH / 2) - (line.wall_line_height / 2);
	while (y_win >= y_min_win)
	{
		color = get_color(line, y_size_on_wall);
		if (line.x_win > 0 && line.x_win < WIN_WIDTH
			&& y_win > 0 && y_win < WIN_HEIGTH)
			ft_mlx_pixel_put(game, line.x_win, y_win, color);
		y_size_on_wall *= 2;
		y_win--;
	}
}
