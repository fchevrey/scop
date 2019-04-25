/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_to_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:01:23 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/25 20:10:52 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

static void		column_major(float *array, const t_4matrix *src)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			array[i] = src->n[x][y];
			i++;
			x++;
		}
		y++;
	}
}

void			m4_to_float(float *array, const t_4matrix *src,
		int is_column_major)
{
	int		i;
	int		x;
	int		y;

	if (is_column_major)
	{
		column_major(array, src);
		return ;
	}
	x = 0;
	i = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			array[i] = src->n[x][y];
			y++;
			i++;
		}
		x++;
	}
}
