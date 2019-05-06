#include "rendering.h"

void		render(t_data* data)
{
	t_4matrix		model_tmp;
	float			model_arr[16];
	float			view_arr[16];

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	//glBindTexture(GL_TEXTURE_2D, data->tex_ref);
	glUseProgram(data->shader_prog[data->render_mode]);
	glBindVertexArray(data->vao);
	model_tmp = m4_rotation(data->rot_axis, data->rot_speed);
//	model_tmp = m4_rotation(vecfl_set(1.0, 0.0, 0.5), 1.5f);
	data->model = m4_op(&model_tmp, '*', &data->model);
	//data->model = m4_rotation(data->rot_axis, data->rot_speed * (float)SDL_GetTicks());
	m4_to_float(model_arr, &data->model, 1);
	m4_to_float(view_arr, &data->view, 1);
	unsigned int modelLoc = glGetUniformLocation(
			data->shader_prog[data->render_mode], "model");
	unsigned int viewLoc  = glGetUniformLocation(
			data->shader_prog[data->render_mode], "view");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model_arr);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view_arr);
	glDrawElements(GL_TRIANGLES, data->ebo_size, GL_UNSIGNED_INT, 0);//
	SDL_GL_SwapWindow(data->win->ptr);
}
