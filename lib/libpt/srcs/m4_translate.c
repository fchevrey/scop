/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:19:37 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/26 14:27:08 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_4matrix	m4_translate(t_vecfl factors)
{
	t_4matrix		m;

	m = m4_identity();
	m.n[0][3] = factors.x;
	m.n[1][3] = factors.y;
	m.n[2][3] = factors.z;
	return (m);
}
