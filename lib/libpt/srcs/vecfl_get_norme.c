/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecfl_get_norme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:23:15 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/30 15:39:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include <math.h>

float		vecfl_get_norme(t_vecfl src)
{
	return (sqrtf((src.x * src.x) + (src.y * src.y) + (src.z * src.z)));
}
