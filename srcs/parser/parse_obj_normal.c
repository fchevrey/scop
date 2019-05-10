/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:45:19 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:45:27 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_obj_normal(t_parse *parse, char **line)
{
	size_t		size;

	parse->is_normal = 1;
	read_float_arr(parse, line, "vn ", 3);
	size = lst_to_arr(parse->buf_lst, &parse->normal_buffer->buf);
	parse->normal_buffer->size = size;
	ft_lstdel(&parse->buf_lst, &free_elem);
	if (!parse || !line)
		return (1);
	return (1);
}
