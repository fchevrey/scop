/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:31:29 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/30 18:40:01 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include <fcntl.h>

int				read_vertex(int fd, t_parse *parse, char *first_line)
{
	int			quit;
	int			rd;

	quit = 0;
	while (!quit)
	{
		if ((rd = get_next_line(fd, &line)) == -1)
			return (0);
		if (!line)
			break ;
		if ()
	}
}

static int		preffix_ok(const char *s1, const char **cmp)
{
	int		i;

	i = 0;
	while (cmp[i])
	{
		if (compare(s1, cmp[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int		compare(const char *s1, const char *cmp)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (cmp[i])
	{
		if (cmp[i] != s1[i])
			return (-1);
		i++;
	}
	return (0);
}

static int		read_all(int fd, t_data *data, t_parse *parse)
{
	char		*line;
	char		*vertex;
	int			quit;

	quit = 0;
	while (!quit)
	{
		get_next_line(fd, &line);
		if (!line)
			return (1);
		else if (line[0] == '#')
		else if (line[0] == 'v' && line[1] == 't')
		else if (line[0] == 'v' && line[1] == ' ')
		else if (line[0] == 'v' && line[1] == 'n')
		else if (line[0] == 'f')
		else if (line[0] == '#')

		ft_strdel(&line);
	}
	return (1);
}

int		parse(t_data *data, char *filename)
{
	int			fd;
	t_parse		parse;
	char		**cmp;

	if (!filename)
		return (0);
	if ((fd = open(filename, O_RDONLY | O_NOFOLLOW)) == -1)
		return (0);
	cmp = ft_strsplit("v |vt | vn |f ", '|');
	read_all(fd, data, &parse);
	close(fd);
	return (1);
}
