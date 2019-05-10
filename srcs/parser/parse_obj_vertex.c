/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:56:30 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:45:45 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_obj_vertex(t_parse *parse, char **line)
{
	size_t		size;

	read_float_arr(parse, line, "v ", 3);
	size = lst_to_arr(parse->buf_lst, &parse->vertex_buffer->buf);
	parse->vertex_buffer->size = size;
	ft_lstdel(&parse->buf_lst, &free_elem);
	return (1);
}
