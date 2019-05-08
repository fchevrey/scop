/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lst4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:19:21 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/08 14:30:47 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	void			reorder_tmp(t_face_info *info)
{
	info->tmp_v[0] = info->tmp_v[0];
	info->tmp_v[1] = info->tmp_v[2];
	info->tmp_v[2] = info->tmp_v[3];
	info->tmp_t[0] = info->tmp_t[0];
	info->tmp_t[1] = info->tmp_t[2];
	info->tmp_t[2] = info->tmp_t[3];
	info->tmp_n[0] = info->tmp_n[0];
	info->tmp_n[1] = info->tmp_n[2];
	info->tmp_n[2] = info->tmp_n[3];
}

static int		check(t_parse *parse, t_face_info *info, int scan)
{
	if ((scan % 4 != 0 || scan != info->len)
		|| (parse->is_normal && parse->is_texture && scan != 12)
		|| ((!parse->is_normal && parse->is_texture) && scan != 8)
		|| ((parse->is_normal && !parse->is_texture) && scan != 8))
		return (0);
	return (1);
}

int				add_to_lst4(t_parse *parse, t_face_info *info,
		int scan, int count)
{
	t_list		*elem;

	if (count < 0)
		return (1);
	if (!check(parse, info, scan))
		return (0);
	if (!(elem = ft_lstnew_cpy(info->tmp_v, sizeof(float) * 3, 3)))
		return (0);
	ft_lstadd_last(parse->vert_index->lst, elem);
	if (scan > 7 && parse->is_texture)
	{
		if (!(elem = ft_lstnew_cpy(info->tmp_t, sizeof(float) * 2, 2)))
			return (0);
		ft_lstadd_last(parse->tex_index->lst, elem);
	}
	if (scan > 7 && parse->is_normal)
	{
		if (!(elem = ft_lstnew_cpy(info->tmp_n, sizeof(float) * 3, 3)))
			return (0);
		ft_lstadd_last(parse->norm_index->lst, elem);
	}
	reorder_tmp(info);
	return (add_to_lst4(parse, info, scan, count -1));
}
