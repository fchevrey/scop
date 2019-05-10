/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_render_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:53:14 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 11:36:52 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		other_render_mode(t_data *data, int render_mode)
{
	if (render_mode == 3)
	{
		data->timer = 1.0f;
		data->is_tex = 1;
	}
	else if (render_mode == 4)
	{
		data->is_tex = 0;
		data->is_time = 1;
		data->timer = 1.0f;
	}
	else if (render_mode == 5)
	{
		data->is_time = 1;
		data->is_3dtex = 1;
		data->timer = 1.0f;
	}
}

void			change_render_mode(t_data *data)
{
	static int		render_mode = 0;

	render_mode++;
	if (render_mode > 5)
		render_mode = 0;
	if (render_mode == 0)
	{
		data->is_grey = 1;
		data->is_tex = 0;
		data->is_flat = 1;
		data->is_time = 0;
		data->is_3dtex = 0;
	}
	else if (render_mode == 1)
	{
		data->is_grey = 0;
		data->is_flat = 1;
	}
	else if (render_mode == 2)
		data->is_flat = 0;
	else
		other_render_mode(data, render_mode);
}
