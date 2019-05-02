/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_float_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:01:13 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/02 18:01:25 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int				parse_line(t_list *lst, t_line_info *info, char *line)
{
	int		scan;

	scan = 0;
	if (info->len == 2)
	{
		scan = sscanf(line, info->format, &info->tmp[0], &info->tmp[1]);
	}
	else if (info->len == 3)
	{
		scan = sscanf(line, info->format, &info->tmp[0], &info->tmp[1],
				&info->tmp[2]);
	}
	else if (info->len == 4)
	{
		scan = sscanf(line, info->format, &info->tmp[0], &info->tmp[1],
					&info->tmp[2], &info->tmp[3]);
	}
	if (scan > 0 && lst)
		lst->next = ft_lstnew_cpy(info->tmp, sizeof(float) * info->len, scan);
	return (scan);
}

static char				*create_format(char *pref, int size)
{
	if (size == 2)
		return (ft_strjoin(pref, "%f%f"));
	if (size == 3)
		return (ft_strjoin(pref, "%f%f%f"));
	if (size == 4)
		return (ft_strjoin(pref, "%f%f%f%f"));
	return (NULL);
}
static int		init_info(char *pref, int size, t_line_info *info)
{
	if (!(info->tmp = (float*)malloc(sizeof(float) * size)))
		return (0);
	info->format = create_format(pref, size);
	info->len = size;
	return (1);
}

static void		del_info(t_line_info *info)
{
	if (info->format)
		ft_strdel(&info->format);
	if (info->tmp)
		free(info->tmp);
	info->tmp = NULL;
}

int				read_float_arr(t_parse *parse, char **line, char *pref, int size)
{
	int				rd;
	t_line_info		info;
	t_list			*lst;

	if (!init_info(pref, size, &info))
		return (0);
	if (parse_line(NULL, &info, *line) <= 0)
		return (0);
	parse->buf_lst = ft_lstnew_cpy(info.tmp, sizeof(float) * info.len, size);//must be source of error
	lst = parse->buf_lst;
	ft_strdel(line);
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
		parse_line(lst, &info, *line);
		lst = lst->next;
		ft_strdel(line);
	}
	del_info(&info);
	return (1);
}
