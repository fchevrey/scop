/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:31:29 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/01 18:19:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include <fcntl.h>

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
		/*else if (line[0] == '#')
		else if (line[0] == 'v' && line[1] == 't')
		else if (line[0] == 'v' && line[1] == 'n')
		else if (line[0] == 'f')
		else if (line[0] == '#')*/

		ft_strdel(&line);
	}
	return (1);
}

int		parse(t_data *data, char *filename)
{
	t_parse		parse;

	if (!filename)
		return (0);
	if ((parse.fd = open(filename, O_RDONLY | O_NOFOLLOW)) == -1)
		return (0);
	parse.cmp = ft_strsplit("v |vt | vn |f ", '|');
	read_all(data, &parse);
	close(parse.fd);
	return (1);
}
