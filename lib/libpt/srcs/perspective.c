/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:39:45 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/25 19:39:06 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include <math.h>

t_4matrix		perspective(float angle, float ratio,
float near, float far)
{
	t_4matrix		dst;
	float			tan_half;

	dst = m4_zero();
	angle = deg_to_rad(angle);
	tan_half = tanf(angle / 2);
	dst.n[0][0] = 1 / (ratio * tan_half);
	dst.n[1][1] = 1 / (tan_half);
	dst.n[2][2] = -(far + near) / (far - near);
	dst.n[3][2] = -1;
	dst.n[2][3] = -(2 * far * near) / (far - near);
	return (dst);
}
