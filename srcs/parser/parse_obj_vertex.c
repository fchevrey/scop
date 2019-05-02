/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:56:30 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/02 18:50:43 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

/*int				read_vertex(t_parse *parse, char **line, char *pref, int size)
{
	int				rd;
	t_line_info		info;
	t_list			*lst;
	int pouet = 0;

	info.tmp = (float*)malloc(sizeof(float) * size);
	info.format = create_format(pref, size);
	info.len = size;

	if (parse_line(NULL, &info, *line) <= 0)
		return (0);
	//if (sscanf(*line, "v %f%f%f", &tmp[0], &tmp[1], &tmp[2]) < 3)
	//	return (0);
	lst = parse->buf_lst;
//	while ((rd = get_next_line(parse->fd, line)) != -1)
	ft_putendl(info.format);
	ft_putendl(pref);
	while ((rd = get_next_line(parse->fd, line)) > 0)
	{
		if (!*line)
			continue ;
		if (!compare_prefix(*line, pref))
		{
			if ((pouet = prefix_ok(*line, parse->cmp)) >= 0)
				break;
			continue;
		}
		if (sscanf(*line, "a %f%f%f", &tmp[0], &tmp[1], &tmp[2]) < size)
			return (0);
		lst->next = ft_lstnew_cpy(tmp, sizeof(float) * size, size);
		lst = lst->next;
	}
	ft_strdel(&info.format);
	free(info.tmp);
	return (1);
}*/

static void		print_float(t_list *elem)
{
	static int		i = 0;
	float			*arr;

	arr = (float*)elem->content;
	printf("%d : %f %f %f\n", i, arr[0], arr[1], arr[2]);
	i++;
}

int		parse_obj_vertex(t_parse *parse, char **line)
{
	ft_putendl("- vertex -");
	read_float_arr(parse, line, "v ", 3);
	ft_lstiter(parse->buf_lst, &print_float);
	ft_lstdel(&parse->buf_lst, &free_elem);
	return (1);
}
