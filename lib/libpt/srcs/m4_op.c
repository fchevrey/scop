/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:23:40 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/25 15:05:08 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

static t_4matrix		add(const t_4matrix *m1, const t_4matrix *m2)
{
	t_4matrix		dst;
	int				x;
	int				y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			dst.n[x][y] = m1->n[x][y] + m2->n[x][y];
			y++;
		}
		x++;
	}
	return (dst);
}

static t_4matrix		minus(const t_4matrix *m1, const t_4matrix *m2)
{
	t_4matrix		dst;
	int				x;
	int				y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			dst.n[x][y] = m1->n[x][y] - m2->n[x][y];
			y++;
		}
		x++;
	}
	return (dst);
}

static t_4matrix		multiply(const t_4matrix *m1, const t_4matrix *m2)
{
	t_4matrix		dst;
	int				x;
	int				y;
	t_quatfl		row;
	t_quatfl		col;

	x = 0;
	while (x < 4)
	{
		y = 0;
		row = quatfl_set(m1->n[x][0], m1->n[x][1], m1->n[x][2], m1->n[x][3]);
		while (y < 4)
		{
			col = quatfl_set(m2->n[0][y], m2->n[1][y], m2->n[2][y],
				m2->n[3][y]);
			dst.n[x][y] = (row.x * col.x) + (row.y * col.y) + (row.z * col.z)
				+ (row.w * col.w);
			y++;
		}
		x++;
	}
	return (dst);
}

static t_4matrix		divide(const t_4matrix *m1, const t_4matrix *m2)
{
	t_4matrix		dst;
	int				x;
	int				y;
	t_quatfl		row;
	t_quatfl		col;

	x = 0;
	while (x < 4)
	{
		y = 0;
		row = quatfl_set(m1->n[x][0], m1->n[x][1], m1->n[x][2], m1->n[x][3]);
		while (y < 4)
		{
			col = quatfl_set(m2->n[0][y], m2->n[1][y], m2->n[2][y],
				m2->n[3][y]);
			dst.n[x][y] = (row.x / col.x) + (row.y / col.y) + (row.z / col.z)
				+ (row.w / col.w);
			y++;
		}
		x++;
	}
	return (dst);
}

t_4matrix		m4_op(const t_4matrix *m1, char operand, const t_4matrix *m2)
{
	if (operand == '-')
	{
		return (minus(m1, m2));
	}
	else if (operand == '+')
	{
		return (add(m1, m2));
	}
	else if (operand == '*')
	{
		return (multiply(m1, m2));
	}
	else if (operand == '/')
	{
		return (divide(m1, m2));
	}
	return *m1;
}
