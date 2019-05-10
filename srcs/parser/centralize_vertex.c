/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centralise_vert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:26:34 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:52:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "parser.h"

static t_vecfl		get_center(float *buf, size_t size)
{
	t_vecfl		min;
	t_vecfl		max;
	size_t		i;
	t_vecfl		center;

	i = 0;
	min = vecfl_set(buf[i], buf[i + 1], buf[i + 2]);
	max = vecfl_set(buf[i], buf[i + 1], buf[i + 2]);
	while (i + 2 < size)
	{
		min.x = fminf(buf[i], min.x);
		min.y = fminf(buf[i + 1], min.y);
		min.z = fminf(buf[i + 2], min.z);
		max.x = fmaxf(buf[i], max.x);
		max.y = fmaxf(buf[i + 1], max.y);
		max.z = fmaxf(buf[i + 2], max.z);
		i += 3;
	}
	center.x = (max.x + min.x) * 0.5f;
	center.y = (max.y + min.y) * 0.5f;
	center.z = (max.z + min.z) * 0.5f;
	return (center);
}

t_vecfl				centralize_vertex(t_float_buf *src)
{
	t_vecfl		center;
	size_t		i;

	if (src->size < 3)
		return (vecfl_set(1.0f, 1.0f, 1.0f));
	center = get_center(src->buf, src->size);
	i = 0;
	while (i < src->size)
	{
		src->buf[i] -= center.x;
		src->buf[i + 1] -= center.y;
		src->buf[i + 2] -= center.z;
		i += 3;
	}
	return (center);
}
