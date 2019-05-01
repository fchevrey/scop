/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:46:22 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/01 16:15:31 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_next(t_parse *parse, char **line)
{
	static t_funar_parse	*funs = NULL;
	int						size;
	int						i;

	if (!funs)
		if (!(funs = fill_funar_parse(&size)))
			return ;
	if (parse->parse_type == PARSE_EXIT)
	{
		free(funs);
		return ;
	}
	i = 0;
	while (i < size)
	{
		if (funs[i].key == parse->parse_type)
			funs[i].f(parse, line);
		i++;
	}
}
