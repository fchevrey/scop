/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_face_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:53:53 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static char		*create_format(char *pref, int size)
{
	if (size == 4)
		return (ft_strjoin(pref, "%d %d %d %d"));
	if (size == 8)
		return (ft_strjoin(pref, "%d/%d %d/%d %d/%d %d/%d"));
	if (size == 12)
	{
		return (ft_strjoin(pref,
			"%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d"));
	}
	return (NULL);
}

int				init_face_info(char *pref, int size, t_face_info *info)
{
	if (!(info->tmp_v = (unsigned int*)malloc(sizeof(unsigned int) * 4)))
		return (0);
	if (!(info->tmp_t = (unsigned int*)malloc(sizeof(unsigned int) * 4)))
		return (0);
	if (!(info->tmp_n = (unsigned int*)malloc(sizeof(unsigned int) * 4)))
		return (0);
	if (!(info->format = create_format(pref, size)))
		return (0);
	info->len = size;
	return (1);
}
