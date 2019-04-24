/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_bc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:05:05 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/24 16:19:42 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_4matrix		m4_bc(const t_4matrix *m1, char operand, float nb)
{
	t_4matrix		dst;
	int				x;
	int				y;

	x = 0;
	dst = *m1;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (operand == '-')
				dst.n[x][y] = m1->n[x][y] - nb;
			else if (operand == '+')
				dst.n[x][y] = m1->n[x][y] + nb;
			else if (operand == '*')
				dst.n[x][y] = m1->n[x][y] * nb;
			else if (operand == '/')
				dst.n[x][y] = m1->n[x][y] / nb;
			y++;
		}
		x++;
	}
	return (dst);
}
