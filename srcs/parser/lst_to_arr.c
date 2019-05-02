/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:50:20 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/02 19:55:06 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	compute_length(t_list *lst)
{
	size_t		dst;

	dst = 0;
	while (lst)
	{
		dst += lst->id;
		lst = lst->next;
	}
	return (dst);
}

static void		fill(t_list *lst, float *arr)
{
	size_t		i;
	size_t		j;
	float		*tmp;

	i = 0;
	while (lst)
	{
		j = 0;
		tmp = (float*)lst->content;
		while (j < lst->id)
		{
			arr[i + j] = tmp[j];
			j++;
		}
		i += j;
		lst = lst->next;
	}
}

size_t			lst_to_arr(t_list	*lst, float **to_fill)
{
	size_t		size;

	size = compute_length(lst);
	if (!size)
		return (0);
	if (!(*to_fill = (float*)malloc(sizeof(float) * size)))
		return (0);
	fill(lst, *to_fill);
	return (size);
}
