/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecfl_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:43:58 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/30 15:44:01 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

void		vecfl_normalize(t_vecfl *src)
{
	float		norm;

	norm = vecfl_get_norme(*src);
	if (norm == 0.0f)
		return ;
	src->x /= norm;
	src->y /= norm;
	src->z /= norm;
}
