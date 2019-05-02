/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_funar_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:29:57 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/02 18:35:31 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

static t_funar_parse		add_one(int key, int (*f)(t_parse*, char **))
{
	t_funar_parse	item;

	item.key = key;
	item.f = f;
	return (item);
}

t_funar_parse			*fill_funar_parse(int *size)
{
	t_funar_parse	*tab;
	int				nb_fct;
	int				i;

	i = 0;
	*size = 0;
	nb_fct = 4;
	if (!(tab = (t_funar_parse*)malloc(sizeof(t_funar_parse) * nb_fct)))
		return (NULL);
	*size = nb_fct;
	tab[i++] = add_one(PARSE_VERTEX, &parse_obj_vertex);
	tab[i++] = add_one(PARSE_TEXTURE, &parse_obj_texture);
	tab[i++] = add_one(PARSE_NORMAL, &parse_obj_normal);
	tab[i++] = add_one(PARSE_FACE, &parse_obj_face);
	return (tab);
}
