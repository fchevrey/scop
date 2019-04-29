/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:25:36 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/29 18:30:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void		resize(t_data *data, int width, int height)
{
	data->win->size = pt_set(width, height);
	glViewport(0, 0, width, height);
}
