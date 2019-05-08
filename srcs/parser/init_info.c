/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:44:05 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/08 14:06:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char		*create_format(char *pref, int size)
{
	if (size == 2)
		return (ft_strjoin(pref, "%f%f"));
	if (size == 3)
		return (ft_strjoin(pref, "%f%f%f"));
	if (size == 4)
		return (ft_strjoin(pref, "%f%f%f%f"));
	return (NULL);
}

int				init_info(char *pref, int size, t_line_info *info)
{
	if (!(info->tmp = (float*)malloc(sizeof(float) * size)))
		return (0);
	info->format = create_format(pref, size);
	info->len = size;
	return (1);
}
