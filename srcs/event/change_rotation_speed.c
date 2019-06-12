/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_rotation_speed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:30:26 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/13 15:48:14 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void		rotation_speed_up(t_data *data)
{
	data->rot_speed += 1.0f;
}

void		rotation_speed_down(t_data *data)
{
	data->rot_speed -= 1.0f;
	if (data->rot_speed < 0.00f)
		data->rot_speed = 0.0f;
}
