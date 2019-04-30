/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:56:30 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/30 18:54:53 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

int		parse_obj_vertex(char *vertex, t_data *data)
{
	char		**v;
	t_vecfl		tmp;
	int			i;

	v = ft_strsplit(vextex, '\n');
	i = 0;
	sscanf(v[i], "%f%f%f", &tmps.x, &tmp.y, &tmp.z);
	return (1);
}
