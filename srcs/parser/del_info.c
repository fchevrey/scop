/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:44:05 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 13:44:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		del_info(t_line_info *info)
{
	if (info->format)
		ft_strdel(&info->format);
	if (info->tmp)
		free(info->tmp);
	info->tmp = NULL;
}
