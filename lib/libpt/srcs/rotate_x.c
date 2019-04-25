/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:02:14 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/25 15:07:28 by fchevrey         ###   ########.fr       */
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
	dst.y = (cosf(rad) * src.y) - (sinf(rad) * src.z);
	dst.z = (sinf(rad) * src.y) + (cosf(rad) * src.z);
	return (dst);
}
