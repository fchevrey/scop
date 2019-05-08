/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:46:22 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/08 14:35:00 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		free_funar(t_funar_parse **funs)
{
	free(*funs);
	*funs = NULL;
	return (0);
}

int				parse_next(t_parse *parse, char **line)
{
	static t_funar_parse	*funs = NULL;
	static int				size;
	int						i;

	if (!funs)
	{
		if (!(funs = fill_funar_parse(&size)))
			return (0);
	}
	if (parse->parse_type == PARSE_EXIT)
		return (free_funar(&funs));
	i = 0;
	while (i < size)
	{
		if (funs[i].key == parse->parse_type)
		{
			funs[i].f(parse, line);
			funs[i].key = -2;
			return (1);
		}
		i++;
	}
	return (0);
}
