/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:39:45 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 16:29:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include <math.h>

t_4matrix		perspective(float angle, t_ptfl screen,
float near, float far)
{
	t_4matrix		dst;
	float			tan_half;
	float			ratio;
	float			t;
	float			r;

	dst = m4_zero();
	ratio = screen.x / screen.y;
	angle = deg_to_rad(angle);
	tan_half = tanf(angle / 2);
	t = tan_half * near;
	r = ratio * t;
	dst.n[0][0] = (2 * near) / (r * 2);
	dst.n[1][1] = (2 * near) / (t * 2);
	dst.n[2][2] = -(far + near) / (far - near);
	dst.n[3][2] = -1;
	dst.n[2][3] = -(2 * far * near) / (far - near);
	dst.n[0][2] = 0;
	dst.n[1][2] = 0;
	return (dst);
}
