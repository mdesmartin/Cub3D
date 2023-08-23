/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:58:06 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/23 17:44:55 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_col_point	ft_float_collision(t_data *game, float angle)
{
	t_col_point	horizontal;
	t_col_point	vertical;

	horizontal = ft_hori_collision(game, angle);
	vertical = ft_vert_collision(game, angle);
	if (vertical.face == '\0')
		return (horizontal);
	else if (horizontal.face == '\0')
		return (vertical);
	if (vertical.depth > horizontal.depth)
		return (horizontal);
	else
		return (vertical);
}

t_col_point	ft_3d_wall_collision(t_data *game, float angle)
{
	t_col_point	wall;

	wall = ft_float_collision(game, angle);
	wall.depth = cosf(game->degree - angle) * wall.depth;
	return (wall);
}
