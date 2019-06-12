/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:53:10 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/13 15:41:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void		init_matrix(t_data *data)
{
	data->rot_speed = 2.0f;
	data->rot_axis = vecfl_set(0.0f, 0.5f, 0.0f);
	vecfl_normalize(&data->rot_axis);
	data->model = m4_rotation(data->rot_axis,
			data->rot_speed * (float)SDL_GetTicks());
	data->view = m4_translate(vecfl_set(0.0f, 0.0f, -3.0f));
	data->proj = perspective(90.0f,
			ptfl_set((float)WIN_WIDTH, (float)WIN_HEIGHT), 0.1f, 100.0f);
	set_projection_matrix(data);
}
