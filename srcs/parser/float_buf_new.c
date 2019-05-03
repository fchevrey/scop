/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_buf_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:44:28 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 15:08:42 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_float_buf		*float_buf_new(void)
{
	t_float_buf		*dst;

	dst = (t_float_buf*)malloc(sizeof(t_float_buf));
	dst->lst = NULL;
	dst->buf = NULL;
	dst->size = 0;
	return (dst);
}
