/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:51:41 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 16:51:55 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include <math.h>

t_4matrix	m4_rotation(t_vecfl axe, float angle)
{
	t_4matrix	dst;
	float		cos;
	float		sin;
	float		cos_inverse;

	angle = deg_to_rad(angle);
	cos = cosf(angle);
	cos_inverse = 1 - cos;
	sin = sinf(angle);
	dst = m4_zero();
	dst.n[0][0] = (axe.x * axe.x * cos_inverse) + cos;
	dst.n[0][1] = (axe.x * axe.y * cos_inverse) - (axe.z * sin);
	dst.n[0][2] = (axe.x * axe.z * cos_inverse) + (axe.y * sin);
	dst.n[1][0] = (axe.x * axe.y * cos_inverse) + (axe.z * sin);
	dst.n[1][1] = (axe.y * axe.y * cos_inverse) + cos;
	dst.n[1][2] = (axe.y * axe.z * cos_inverse) - (axe.x * sin);
	dst.n[2][0] = (axe.x * axe.z * cos_inverse) - (axe.y * sin);
	dst.n[2][1] = (axe.y * axe.z * cos_inverse) + (axe.x * sin);
	dst.n[2][2] = (axe.z * axe.z * cos_inverse) + cos;
	dst.n[3][3] = 1;
	return (dst);
}
