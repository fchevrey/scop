/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_float_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:47:41 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 14:53:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		free_float_buf(t_float_buf **src)
{
	if (!src || *src)
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
