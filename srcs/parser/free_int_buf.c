/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:15:05 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/04 12:07:19 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		free_int_buf(t_int_buf **src)
{
	if (!src || !*src)
		return ;
	if ((*src)->lst)
	{
		ft_lstdel(&(*src)->lst, &free_elem);
	}
	(*src)->lst = NULL;
	if ((*src)->buf)
		free((*src)->buf);
	(*src)->buf = NULL;
	free(*src);
	*src = NULL;
}
