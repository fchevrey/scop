/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:31:05 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 15:49:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int				add_to_lst(t_parse *parse, t_face_info *info, int scan)
{
}

static int				parse_line(t_parse *parse, t_face_info *info, char *line)
{
	int		scan;

	scan = 0;
	if (info->len == 4)
	{
		scan = sscanf(line, info->format, &info->vert_index[0],
			&info->vert_index[1], &info->vert_index[2], &info->vert_index[3]);
	}
	else if (info->len == 8)
	{
		scan = sscanf(line, info->format, &info->vert_index[0],
			&info->vert_index[1], &info->vert_index[2], &info->vert_index[3],
			&info->tex_index[0], &info->tex_index[1], &info->tex_index[2],
			&info->tex_index[3]);
	}
	else if (info->len == 12)
	{
		scan = sscanf(line, info->format, &info->vert_index[0],
			&info->vert_index[1], &info->vert_index[2], &info->vert_index[3],
			&info->tex_index[0], &info->tex_index[1], &info->tex_index[2],
			&info->tex_index[3], &info->norm_index[0], &info->norm_index[1],
			&info->norm_index[2], &info->norm_index[3]);
	}
	return (add_to_lst(parse, info, scan));
}

static int		loop(t_parse *parse, char **line, char *pref,
		t_line_info *info)
{
	int				rd;
	t_list			*lst;
	int				length;

	lst = parse->buf_lst;
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
		parse_line(lst, info, *line);
		lst = lst->next;
		ft_strdel(line);
	}
	return (length);
}

int				read_face(t_parse *parse, char **line, char *pref)
{
	t_line_info		info;
	int				ret;
	int				size;
	int				line_size;

	if (parse->is_texture && parse->is_normal)
		size = 15;
	else if (parse->is_texture || parse->is_normal)
		size = 10;
	else
		size = 5;
	if (!init_info(pref, size, &info))
		return (0);
	if ((line_size = parse_line(NULL, &info, *line)) <= 0)
		return (0);
	if (!(parse->buf_lst = ft_lstnew_cpy(info.tmp, sizeof(float) * line_size,
					line_size)))
		return (0);
	ret = 0;
	ret = loop(parse, line, pref, &info);
	del_info(&info);
	return (ret);
}
