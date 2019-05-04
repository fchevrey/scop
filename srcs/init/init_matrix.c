/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:53:10 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/04 14:04:00 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void		init_matrix(t_data *data)
{
	float		proj_arr[16];
	data->rot_axe = vecfl_set(0.5f, 0.0f, 0.0f);
	vecfl_normalize(&data->rot_axe);
	data->model = m4_rotation(data->rot_axe, 50.0f * (float)SDL_GetTicks());
	data->view = m4_translate(vecfl_set(0.0f, 0.0f, -5.0f));
	data->proj = perspective(90.0f,
			ptfl_set((float)WIN_WIDTH, (float)WIN_HEIGHT), 0.1f, 100.0f);
	m4_to_float(proj_arr, &data->proj, 1);
	glUniformMatrix4fv(glGetUniformLocation(data->shader_prog, "projection"),
			1, GL_FALSE, proj_arr);
}
