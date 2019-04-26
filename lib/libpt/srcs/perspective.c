/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:39:45 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/26 17:18:21 by fchevrey         ###   ########.fr       */
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
	float			b;
	float			r;
	float			l;

	dst = m4_zero();
	ratio = screen.x / screen.y;
	angle = deg_to_rad(angle);
	tan_half = tanf(angle / 2);
	//t = tan_half * near;
//	r = t * ratio * near;
	r = ratio * tan_half * near;
	//l = -t * ratio;
	l = -r;
	t = tan_half * near;
	b = -t;
	ft_putendl("pouet");
	/*m0 column major*/  //work but weird
	dst.n[0][0] = (2 * near) / (r - l);
	dst.n[1][1] = (2 * near) / (t - b);
	dst.n[2][2] = -(far + near) / (far - near);
	dst.n[3][2] = -1;
	dst.n[2][3] = -(2 * far * near) / (far - near);
	dst.n[0][2] = (r + l) / (r - l);
	dst.n[1][2] = (t + b) / (t - b);
	
	/*m0 row major //don't work
	dst.n[0][0] = (2 * near) / (r - l);
	dst.n[1][1] = (2 * near) / (t - b);
	dst.n[2][2] = -(far + near) / (far - near);
	dst.n[2][3] = -1;
	dst.n[3][2] = -(2 * far * near) / (far - near);
	dst.n[2][0] = (r + l) / (r - l);
	dst.n[2][1] = (t + b) / (t - b);
	*/
	/*m1 //work but weird
	dst.n[0][0] = 1 / (ratio * tan_half);
	dst.n[1][1] = 1 / (tan_half);
	dst.n[2][2] = -(far + near) / (far - near);
	dst.n[3][2] = -1;
	dst.n[2][3] = -(2 * far * near) / (far - near);
	*/
	/*m2
	dst.n[0][0] = 1 / (ratio * tan_half);
	dst.n[1][1] = 1 / (tan_half);
	dst.n[2][2] = -(far + near) / (near -far);
	dst.n[3][2] = 1;
	dst.n[2][3] = -(2 * far * near) / (near - far);*/
	
	/*m3 
	dst.n[0][0] = 2 * near / (ratio - tan_half);
	dst.n[1][1] = 1 / (tan_half);
	dst.n[2][2] = -(far + near) / (near -far);
	dst.n[3][2] = 1;
	dst.n[2][3] = -(2 * far * near) / (near - far);
	*/
	/*m4
	dst.n[0][0] = 1 / (ratio * tan_half);
	dst.n[1][1] = 1 / (tan_half);
	dst.n[2][2] = -far / (far - near);
	//dst.n[2][3] = -1;
	dst.n[2][3] = -(far * near) / (far - near);
	dst.n[3][2] = -1;*/
	return (dst);
}
