/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:25:36 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/04 17:46:48 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void		resize(t_data *data, int width, int height)
{
	float		proj_arr[16];

	data->win->size = pt_set(width, height);
	glViewport(0, 0, width, height);
//	data->proj();
	data->proj = perspective(90.0f,
			ptfl_set((float)width, (float)height), 0.1f, 100.0f);
	m4_to_float(proj_arr, &data->proj, 1);
	glUniformMatrix4fv(glGetUniformLocation(data->shader_prog, "projection"),
			1, GL_FALSE, proj_arr);
}
