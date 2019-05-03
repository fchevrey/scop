/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_face_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:39:10 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 17:40:09 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		del_face_info(t_face_info *info)
{
	if (info->format)
		ft_strdel(&info->format);
	if (info->tmp_v)
		free(info->tmp_v);
	info->tmp_v = NULL;
	if (info->tmp_t)
		free(info->tmp_t);
	info->tmp_t = NULL;
	if (info->tmp_n)
		free(info->tmp_n);
	info->tmp_n = NULL;
}
