/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:31:29 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/02 18:59:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include <fcntl.h>
/*
static int		read_all(t_data *data, t_parse *parse)
{
	char		*line;
	int			quit;

	quit = 0;
	if (!data)
		quit = 1;
	while (!quit)
	{
		get_next_line(parse->fd, &line);
		if (!line)
			return (1);
		else if (line[0] == 'v' && line[1] == ' ')
		{
			parse_obj_vertex(parse, &line);
			quit = 1;
		}
		//else if (line[0] == '#')
		//else if (line[0] == 'v' && line[1] == 't')
	//	else if (line[0] == 'v' && line[1] == 'n')
	//	else if (line[0] == 'f')
	//	else if (line[0] == '#')

		ft_strdel(&line);
	}
	return (1);
}*/
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

static void			free_parse(t_parse **parse)
{
	ft_tabdel((*parse)->cmp);
	*parse = NULL;
}

int		parse(t_data *data, char *filename)
{
	t_parse		parse;

	if (!filename || !data)
		return (0);
	if (!(parse.cmp = ft_strsplit("v |vt |vn |f ", '|')))
		return (0);
	if ((parse.fd = open(filename, O_RDONLY | O_NOFOLLOW)) == -1)
		return (0);
	read_all(&parse);
	close(parse.fd);
	return (1);
}
