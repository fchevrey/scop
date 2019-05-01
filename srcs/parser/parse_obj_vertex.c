/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:56:30 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/01 18:32:27 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int				read_vertex(t_parse *parse, char **line)
{
	int			quit;
	int			rd;
	float		tmp[3];
	t_list		*lst;

	quit = 0;
	if (sscanf(*line, "v %f%f%f", &tmp[0], &tmp[1], &tmp[2]) < 3)
		return (0);
	parse->buf_lst = ft_lstnew_cpy(tmp, sizeof(float) * 3, 3);
	lst = parse->buf_lst;
	while (!quit)
	{
		if ((rd = get_next_line(parse->fd, line)) == -1)
			return (0);
		if (!line)
			continue ;
		if (!compare_prefix(*line, "v "))
		{
			if (prefix_ok(*line, parse->cmp))
				return (1);
			continue;
		}
		if (sscanf(*line, "v %f%f%f", &tmp[0], &tmp[1], &tmp[2]) < 3)
			return (0);
		lst->next = ft_lstnew_cpy(tmp, sizeof(float) * 3, 3);
		lst = lst->next;
	}
	return (1);
}

void	print_float(t_list *elem)
{
	static int		i = 0;
	float			*arr;

	arr = (float*)elem->content;
	printf("%d : %f %f %f\n", i, arr[0], arr[1], arr[2]);
	i++;
}

void	del(void *elem)
{
	ft_strdel((char**)&elem);
}

int		parse_obj_vertex(t_parse *parse, char **line)
{
	read_vertex(parse, line);
	ft_lstiter(parse->buf_lst, &print_float);
	ft_lstdel(&parse->buf_lst, &del);
	return (1);
}
