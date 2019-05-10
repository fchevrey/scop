/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:39:54 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 18:42:03 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void		set_blend_time(t_data *data)
{
	unsigned int	loc;

	loc = glGetUniformLocation(data->shader_prog, "aIs_Blend");
	if (data->timer > 0.000001f)
	{
		if (data->timer > 0.1f)
			data->timer -= 0.02f;
		else
			data->timer -= 0.002f;
		glUniform1i(loc, 1);
	}
	else
	{
		data->timer = 0.0f;
		glUniform1i(loc, 0);
	}
}

static void		set_variable(t_data *data)
{
	unsigned int	loc;
	float			time;
	unsigned int	utime;

	set_blend_time(data);
	loc = glGetUniformLocation(data->shader_prog, "aBlend");
	glUniform1f(loc, data->timer);
	loc = glGetUniformLocation(data->shader_prog, "aIs_tex");
	glUniform1i(loc, data->is_tex);
	loc = glGetUniformLocation(data->shader_prog, "aIs_flat");
	glUniform1i(loc, data->is_flat);
	loc = glGetUniformLocation(data->shader_prog, "aIs_grey");
	glUniform1i(loc, data->is_grey);
	loc = glGetUniformLocation(data->shader_prog, "aIs_time");
	glUniform1i(loc, data->is_time);
	loc = glGetUniformLocation(data->shader_prog, "aIs_dbtex");
	glUniform1i(loc, data->is_dbtex);
	loc = glGetUniformLocation(data->shader_prog, "aTime");
	utime = SDL_GetTicks();
	utime = utime % 2000;
	time = (((float)utime) / 1000) - 1.0f;
	glUniform1f(loc, time);
}

static void		bind_textures(t_data *data)
{
	glActiveTexture(GL_TEXTURE0);
	if (data->is_3dtex)
		glBindTexture(GL_TEXTURE_CUBE_MAP, data->tex_3d);
	else
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, data->tex_refs[data->tex_nb]);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, data->tex_refs[TEXTURE_FOR_BLEND]);
		glUniform1i(glGetUniformLocation(data->shader_prog, "tex1"), 0);
		glUniform1i(glGetUniformLocation(data->shader_prog, "tex2"), 1);
	}
}

void			render(t_data *data)
{
	t_4matrix		model_tmp;
	float			model_arr[16];
	float			view_arr[16];
	unsigned int	mode_loc;
	unsigned int	view_loc;

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(data->shader_prog);
	bind_textures(data);
	set_projection_matrix(data);
	if (!data->is_3dtex)
		set_variable(data);
	glBindVertexArray(data->vao);
	model_tmp = m4_rotation(data->rot_axis, data->rot_speed);
	data->model = m4_op(&model_tmp, '*', &data->model);
	m4_to_float(model_arr, &data->model, 1);
	m4_to_float(view_arr, &data->view, 1);
	model_loc = glGetUniformLocation(data->shader_prog, "model");
	view_loc = glGetUniformLocation(data->shader_prog, "view");
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, model_arr);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, view_arr);
	glDrawElements(GL_TRIANGLES, data->ebo_size, GL_UNSIGNED_INT, 0);
	SDL_GL_SwapWindow(data->win->ptr);
}
