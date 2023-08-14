/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoutous <jmoutous@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:35:25 by jmoutous          #+#    #+#             */
/*   Updated: 2023/08/14 18:15:03 by jmoutous         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	ft_wall_face(float x, float y)
{
	if ((int) x % BOX_SIZE == 0)
		return ('W');
	else if ((int) x % (BOX_SIZE - 1) == 0)
		return ('E');
	else if ((int) y % BOX_SIZE == 0)
		return ('S');
	else if ((int) y % (BOX_SIZE - 1) == 0)
		return ('N');
	return ('\0');
}

float	ft_wall_position(t_point point, char face)
{
	float	res;

	if (point.x % BOX_SIZE == 0 || point.x % (BOX_SIZE - 1) == 0)
	{
		while (point.y > BOX_SIZE)
			point.y -= BOX_SIZE;
		res = (float)point.y / BOX_SIZE;
	}
	else
	{
		while (point.x > BOX_SIZE)
			point.x -= BOX_SIZE;
		res = (float)point.x / BOX_SIZE;
	}
	if (face == 'E' || face == 'S')
		;
	// 	res = 1 - res;
	return (res);
}
