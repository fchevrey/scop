/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:31:29 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 18:17:02 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include <fcntl.h>

static int		read_all(t_parse *parse)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(parse->fd, &line)) > 0)
	{
		while ((parse->parse_type = prefix_ok(line, parse->cmp)) != -1)
		{
			if (!parse_next(parse, &line))
				break;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	parse->parse_type = PARSE_EXIT;
	parse_next(parse, NULL);
	return (1);
}

static void			free_parse(t_parse *parse)
{
	ft_tabdel(&parse->cmp);
	if (parse->buf_lst)
		ft_lstdel(&parse->buf_lst, &free_elem);
	if (parse->vertex_buffer)
		free_float_buf(&parse->vertex_buffer);
	if (parse->tex_buffer)
		free_float_buf(&parse->tex_buffer);
	if (parse->normal_buffer)
		free_float_buf(&parse->normal_buffer);
	if (parse->vert_index)
		free_int_buf(&parse->vert_index);
	if (parse->norm_index)
		free_int_buf(&parse->norm_index);
	if (parse->tex_index)
		free_int_buf(&parse->tex_index);
}
static int			parse_init(t_parse *parse)
{
	parse->cmp = NULL;
	parse->buf_lst = NULL;
	if (!(parse->vertex_buffer = float_buf_new()))
		return (0);
	if (!(parse->tex_buffer = float_buf_new()))
		return (0);
	if (!(parse->normal_buffer = float_buf_new()))
		return (0);
	if (!(parse->vert_index = int_buf_new()))
		return (0);
	if (!(parse->norm_index = int_buf_new()))
		return (0);
	if (!(parse->tex_index = int_buf_new()))
		return (0);
	parse->is_texture = 0;
	parse->is_normal = 0;
	return (1);
}

int		parse(t_data *data, char *filename)
{
	t_parse		parse;

	if (!filename || !data)
		return (0);
	parse_init(&parse);
	if (!(parse.cmp = ft_strsplit("v |vt |vn |f ", '|')))
		return (0);
	if ((parse.fd = open(filename, O_RDONLY | O_NOFOLLOW)) == -1)
		return (0);
	read_all(&parse);
	close(parse.fd);
	free_parse(&parse);
	return (1);
}
