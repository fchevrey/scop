/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:02:14 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/24 18:16:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include <math.h>

t_vecfl			rotate_x(t_vecfl src, float angle)
{
	t_vecfl		dst;
	float		rad;

	rad = deg_to_rad(angle);
	dst.x = src.x;
	dst.y = (cosf(rad) * src.y) - (sinf(rad) * rad.z);
	dst.z = (sinf(rad) * src.y) + (cosf(rad) * rad.z);
	return (dst);
}
