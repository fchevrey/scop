/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_face_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 15:43:19 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static char				*create_format(char *pref, int size)
{
	if (size == 4)
		return (ft_strjoin(pref, "%f %f %f %f"));
	if (size == 8)
		return (ft_strjoin(pref, "%f/%f %f/%f %f/%f %f/%f"));
	if (size == 12)
		return (ft_strjoin(pref,
					"%f/%f/%f %f/%f/%f %f/%f/%f %f/%f/%f"));
	return (NULL);
}

int		init_face_info(char *pref, int size, t_face_info *info)
{
	if (!(info->tmp = (float*)malloc(sizeof(float) * size)))
		return (0);
	if (!(info->format = (pref, size)))
		return (0);
	info->len = size;
	return (1);
}
