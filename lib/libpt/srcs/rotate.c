/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:58:16 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/25 17:53:18 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include <math.h>

/*static t_4matrix	get_matrix(t_vecfl src, t_vecfl axe, float angle)
{
	t_4matrix	dst;

	dst = m4_identity();
	return dst;
}*/

t_vecfl			rotate(t_vecfl src, t_vecfl axe, float angle)
{

	//not implemented yet
	if (src.x == axe.x && axe.x == angle)
		return (src);
	return (src);
}
