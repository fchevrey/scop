/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:56:30 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/04 15:39:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*static void		print_float(t_list *elem)
{
	static int		i = 0;
	float			*arr;

	arr = (float*)elem->content;
	printf("%d : %f %f %f\n", i, arr[0], arr[1], arr[2]);
	i++;
}*/

int		parse_obj_vertex(t_parse *parse, char **line)
{
	size_t		size;

	ft_putendl("- vertex -");
	read_float_arr(parse, line, "v ", 3);
//	ft_lstiter(parse->buf_lst, &print_float);
	size = lst_to_arr(parse->buf_lst, &parse->vertex_buffer->buf);
	parse->vertex_buffer->size = size;
	printf("size vertex = %zu\n", size);
	ft_lstdel(&parse->buf_lst, &free_elem);
	return (1);
}
