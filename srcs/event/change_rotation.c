/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:17:21 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/04 17:29:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void		rotate_in_z_axis(t_data *data)
{
	static int toggle = 0;

	if (toggle)
	{
		data->rot_axis = vecfl_set(0.0f, 0.0f, 0.5f);
	}
	else
	{
		data->rot_axis = vecfl_set(0.0f, 0.0f, -0.5f);
	}
	vecfl_normalize(&data->rot_axis);
	toggle = 1 - toggle;
}

void		rotate_in_x_axis(t_data *data)
{
	static int toggle = 0;

	if (toggle)
	{
		data->rot_axis = vecfl_set(0.5f, 0.0f, 0.0f);
	}
	else
	{
		data->rot_axis = vecfl_set(-0.5f, 0.0f, 0.0f);
	}
	vecfl_normalize(&data->rot_axis);
	toggle = 1 - toggle;
}

void		rotate_in_y_axis(t_data *data)
{
	static int toggle = 0;

	if (toggle)
	{
		data->rot_axis = vecfl_set(0.0f, 0.5f, 0.0f);
	}
	else
	{
		data->rot_axis = vecfl_set(0.0f, -0.5f, 0.0f);
	}
	vecfl_normalize(&data->rot_axis);
	toggle = 1 - toggle;
}
