/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:16:26 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/24 18:17:19 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include <math.h>

t_vecfl			rotate_z(t_vecfl src, float angle)
{
	t_vecfl		dst;
	float		rad;

	rad = deg_to_rad(angle);
	dst.x = (cosf(rad) * src.x) - (sinf(rad) * rad.y);
	dst.y = (sinf(rad) * src.x) + (cosf(rad) * rad.y);
	dst.z = src.z;
	return (dst);
}
