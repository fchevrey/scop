/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:22:53 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/04 15:38:42 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*static void		print_float(t_list *elem)
{
	static int		i = 0;
	float			*arr;

	arr = (float*)elem->content;
	printf("%d : %f %f\n", i, arr[0], arr[1]);
	i++;
}*/
int		parse_obj_texture(t_parse *parse, char **line)
{
	size_t		size;

	ft_putendl("- texture -");
	parse->is_texture = 1;
	read_float_arr(parse, line, "vt ", 2);
//	ft_lstiter(parse->buf_lst, &print_float);
	size = lst_to_arr(parse->buf_lst, &parse->tex_buffer->buf);
	parse->tex_buffer->size = size;
	ft_lstdel(&parse->buf_lst, &free_elem);
	if (!parse || !line)
		return (1);
	return (1);
}
