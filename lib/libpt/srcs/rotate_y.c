/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:14:41 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/24 18:15:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include <math.h>

t_vecfl			rotate_y(t_vecfl src, float angle)
{
	t_vecfl		dst;
	float		rad;

	rad = deg_to_rad(angle);
	dst.x = (cosf(rad) * src.x) - (sinf(rad) * rad.z);
	dst.y = src.y;
	dst.z = (-sinf(rad) * src.y) + (cosf(rad) * rad.z);
	return (dst);
}
