/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:10:51 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/30 18:08:51 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list		*list;
	t_list		*tmp;

	if (alst && *alst)
	{
		list = *alst;
		tmp = list;
		while (list)
		{
			tmp = tmp->next;
			if (del)
				del(list->content);
			free(list);
			list = NULL;
			list = tmp;
		}
		*alst = NULL;
	}
}
