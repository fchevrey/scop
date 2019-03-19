/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecfl_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:07:45 by fchevrey          #+#    #+#             */
/*   Updated: 2018/08/09 12:07:48 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_vec	vecfl_set(float x, float y, float z)
{
	t_vecfl		crd;

	crd.x = x;
	crd.y = y;
	crd.z = z;
	return (crd);
}
