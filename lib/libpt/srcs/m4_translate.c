/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:19:37 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/26 13:19:43 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_4matrix	m4_translate(t_vecfl factors)
{
	t_4matrix		m;

	m = m4_identity();
	m.n[3][0] = factors.x;
	m.n[3][1] = factors.y;
	m.n[3][2] = factors.z;
	return (m);
}
