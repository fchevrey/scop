/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:22:57 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/24 16:31:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

/*static t_4matrix	getfactor(t_vecfl factors)
{
	t_4matrix		m;

	m = m4_identity();
	m.n[3][0] = factors.x;
	m.n[3][1] = factors.y;
	m.n[3][2] = factors.z;
	return (m);
}*/

t_vecfl		translate(t_vecfl  src, t_vecfl factors)
{
	return (vec_op(src, '+', factors));
}
