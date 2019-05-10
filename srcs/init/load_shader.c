/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:23:39 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:19:45 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

static int		test_first_lign(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] < 32 || line[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

static char		*close_exit(int fd)
{
	close(fd);
	return (NULL);
}

char			*load_shader(char *filename)
{
	char		*dst;
	int			fd;
	char		*line;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	get_next_line(fd, &line);
	if (!test_first_lign(line))
		return (close_exit(fd));
	dst = ft_strjoin(line, "\n");
	ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{
		dst = ft_strjoin3f(dst, line, "\n");
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (dst);
}
