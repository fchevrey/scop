/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_buf_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:15:43 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 18:16:13 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_int_buf		*int_buf_new(void)
{
	t_int_buf		*dst;

	if (!(dst = (t_int_buf*)malloc(sizeof(t_int_buf))))
		return (NULL);
	if (!(dst->lst = ft_lstnew(NULL, 0)))
		return (NULL);
	dst->buf = NULL;
	dst->size = 0;
	return (dst);
}
