/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_face.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:48:14 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:50:41 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	compute_length(t_list *lst)
{
	size_t		dst;

	dst = 0;
	while (lst)
	{
		dst += lst->id;
		lst = lst->next;
	}
	return (dst);
}

static void		fill(t_list *lst, unsigned int *arr)
{
	size_t			i;
	size_t			j;
	unsigned int	*tmp;

	i = 0;
	while (lst)
	{
		j = 0;
		tmp = (unsigned int*)lst->content;
		while (j < lst->id)
		{
			arr[i + j] = tmp[j] - 1;
			j++;
		}
		i += j;
		lst = lst->next;
	}
}

static int		create_buf_from_list(t_int_buf *src)
{
	size_t		size;

	size = compute_length(src->lst);
	if (!size)
		return (0);
	if (!(src->buf = (unsigned int*)malloc(sizeof(unsigned int) * size)))
		return (0);
	fill(src->lst, src->buf);
	src->size = size;
	return (1);
}

int				parse_obj_face(t_parse *parse, char **line)
{
	if (!read_face(parse, line, "f "))
		return (0);
	if (create_buf_from_list(parse->vert_index))
		return (0);
	if (parse->is_texture && create_buf_from_list(parse->norm_index))
		return (0);
	if (parse->is_normal && create_buf_from_list(parse->tex_index))
		return (0);
	ft_strdel(line);
	return (1);
}
