/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:58:06 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/23 14:07:42 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_col_point	ft_float_collision(t_data *game)
{
	t_col_point	vertical;
	t_col_point	horizontal;

	vertical = ft_vert_collision(game, game->degree);
	horizontal = ft_hori_collision(game, game->degree);
	if (vertical.face == '\0')
		return (horizontal);
	else if (horizontal.face == '\0')
		return (vertical);
	if (vertical.depth > horizontal.depth)
		return (horizontal);
	else
		return (vertical);
	return (vertical);
}
