/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:31:05 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/04 14:34:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>
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

static int				add_to_lst4(t_parse *parse, t_face_info *info,
		int scan, int count)
{
	t_list		*elem;

	printf("add_to_lst4\n");
	printf("parse->is_normal = %d\n", parse->is_normal);
	printf("parse->is_texture = %d\n", parse->is_texture);
	if ((scan % 4 != 0 || scan != info->len)
		|| (parse->is_normal && parse->is_texture && scan != 12)
		|| ((!parse->is_normal && parse->is_texture) && scan != 8)
		|| ((parse->is_normal && !parse->is_texture) && scan != 8))
		return (0);
	if (count < 0)
		return (1);
	printf("no errors\n");
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

static int				add_to_lst3(t_parse *parse, t_face_info *info, int scan)
{
	t_list		*elem;

	printf("add_to_lst3 \n");
	if ((scan != info->len - 1) && (scan != info->len - 2) &&
			(scan != info->len - 3))
		return (0);
	if (parse->is_normal && parse->is_texture && scan != 9)
		return (0);
	else if ((parse->is_normal || parse->is_texture) && scan < 6)
		return (0);
	if (!(elem = ft_lstnew_cpy(info->tmp_v, sizeof(float) * 3, 3)))
		return (0);
	ft_lstadd_last(parse->vert_index->lst, elem);
	if (scan > 5 && parse->is_texture)
	{
		if (!(elem = ft_lstnew_cpy(info->tmp_t, sizeof(float) * 3, 3)))
			return (0);
		ft_lstadd_last(parse->tex_index->lst, elem);
	}
	if (scan > 5 && parse->is_normal)
	{
		if (!(elem = ft_lstnew_cpy(info->tmp_n, sizeof(float) * 3, 3)))
			return (0);
		ft_lstadd_last(parse->norm_index->lst, elem);
	}
	return (1);
}

static int				parse_line(t_parse *parse, t_face_info *info, char *line)
{
	int		scan;

	scan = 0;
	printf("info->len = %d\n", info->len);
	if (info->len == 4)
	{
		scan = sscanf(line, info->format, &info->tmp_v[0],
			&info->tmp_v[1], &info->tmp_v[2], &info->tmp_v[3]);
	}
	else if (info->len == 8)
	{
		scan = sscanf(line, info->format, &info->tmp_v[0], &info->tmp_t[0],
			&info->tmp_v[1], &info->tmp_t[1], &info->tmp_v[2],
			&info->tmp_t[2], &info->tmp_v[3], &info->tmp_t[3]);
	}
	else if (info->len == 12)
	{
		scan = sscanf(line, info->format, &info->tmp_v[0],
			&info->tmp_t[0], &info->tmp_n[0], &info->tmp_v[1],
			&info->tmp_t[1], &info->tmp_n[1], &info->tmp_v[2],
			&info->tmp_t[2], &info->tmp_n[2], &info->tmp_v[3],
			&info->tmp_t[3], &info->tmp_n[3]);
	}
	printf("scanf = %d\n", scan);
	if (scan < 12 && scan % 3 == 0)
		return (add_to_lst3(parse, info, scan));
	return (add_to_lst4(parse, info, scan, 1));
}

static int		loop(t_parse *parse, char **line, char *pref,
		t_face_info *info)
{
	int				rd;
	int				length;

	ft_strdel(line);
	length = 0;
	while ((rd = get_next_line(parse->fd, line)) > 0)
	{
		if (!*line)
			continue ;
		if (!compare_prefix(*line, pref))
		{
			if (prefix_ok(*line, parse->cmp) >= 0)
				break;
			ft_strdel(line);
			continue;
		}
		++length;
		parse_line(parse, info, *line);
		ft_strdel(line);
	}
	return (length);
}

int				read_face(t_parse *parse, char **line, char *pref)
{
	t_face_info		info;
	int				ret;
	int				size;

	if (parse->is_texture && parse->is_normal)
		size = 12;
	else if (parse->is_texture || parse->is_normal)
		size = 8;
	else
		size = 4;
	if (!init_face_info(pref, size, &info))
		return (0);
	printf("parseline : ");
	printf("%s\n", *line);
	if ((parse_line(parse, &info, *line)) <= 0)
		return (0);
	ret = 0;
	printf("loop\n");
	ret = loop(parse, line, pref, &info);
	printf("ret = %d\n", ret);
	del_face_info(&info);
	return (ret);
}
