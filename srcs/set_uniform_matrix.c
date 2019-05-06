/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uniform_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:08:36 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 16:10:35 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_uniform_matrix(t_data *data)
{
	float		proj_arr[16];
	int			i;

	i = 0;
	m4_to_float(proj_arr, &data->proj, 1);
	while (i < RENDER_MODE_SIZE)
	{
		glUniformMatrix4fv(glGetUniformLocation(data->shader_prog[i],
			"projection"), 1, GL_FALSE, proj_arr);
		i++;
	}
}
