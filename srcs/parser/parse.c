/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:31:29 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/30 15:42:43 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include <fcntl.h>

static int		read_all()
{
	return (1);
}

int		parse(t_data *data, char *filename)
{
	int			fd;
	t_parse		info;

	if (!filename)
		return (0);
	if ((fd = open(filename, O_RDONLY | O_NOFOLLOW)) == -1)
		return (0);
	close(fd);
	return (1);
}
