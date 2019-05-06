/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_render_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:53:14 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 18:25:09 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void		change_render_mode(t_data *data)
{
	data->render_mode++;
	if (data->render_mode >= RENDER_MODE_SIZE)
		data->render_mode = 0;
}
