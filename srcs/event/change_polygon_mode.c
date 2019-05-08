/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_polygon_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:41:00 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/08 16:15:23 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void		change_polygon_mode(t_data *data)
{
	static int		mode = 0;

	if (mode > 2)
		mode = 0;
	if (mode == 0)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (mode == 1)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glPointSize(4);
	}
	else if (mode == 2)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	mode++;
	if (!data)
		return ;
}
