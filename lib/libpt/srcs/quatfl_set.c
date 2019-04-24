/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatfl_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:10:14 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/24 15:12:09 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_quatfl			quatfl_set(float x, float y, float z, float w)
{
	t_quatfl dst;

	dst.x = x;
	dst.y = y;
	dst.z = z;
	dst.w = w;
	return (dst);
}
