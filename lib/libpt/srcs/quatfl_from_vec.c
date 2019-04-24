/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatfl_from_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:12:34 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/24 15:13:35 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_quatfl			quatfl_from_vec(t_vecfl src, float w)
{
	t_quatfl dst;

	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
	dst.w = w;
	return (dst);
}
