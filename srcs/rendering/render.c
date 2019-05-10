#include "rendering.h"

/*static void		set_proj_matrix(t_data *data)
{
	float		proj_arr[16];

	m4_to_float(proj_arr, &data->proj, 1);
	glUniformMatrix4fv(glGetUniformLocation(data->shader_prog,
			"projection"), 1, GL_FALSE, proj_arr);
}*/
static void		set_variable(t_data *data)
{
	unsigned int	loc;
	float			time;
	unsigned int	utime;

	loc = glGetUniformLocation(data->shader_prog, "aBlend");
	if (data->timer > 0.0f)
		data->timer -= 0.02f;
	else
		data->timer = 0.0f;
	glUniform1f(loc, data->timer);
	loc = glGetUniformLocation(data->shader_prog, "aIs_tex");
	glUniform1i(loc, data->is_tex);
	loc = glGetUniformLocation(data->shader_prog, "aIs_flat");
	glUniform1i(loc, data->is_flat);
	loc = glGetUniformLocation(data->shader_prog, "aIs_grey");
	glUniform1i(loc, data->is_grey);
	loc = glGetUniformLocation(data->shader_prog, "aIs_time");
	glUniform1i(loc, data->is_time);
	loc = glGetUniformLocation(data->shader_prog, "aIs_3dtex");
	glUniform1i(loc, data->is_3dtex);
	loc = glGetUniformLocation(data->shader_prog, "aTime");
	utime = SDL_GetTicks();
	utime = utime % 2000;
	time = (((float)utime) / 1000) -1.0f;
	glUniform1f(loc, time);
}

void		render(t_data* data)
{
	t_4matrix		model_tmp;
	float			model_arr[16];
	float			view_arr[16];
	unsigned int	modelLoc;
	unsigned int	viewLoc;

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glUseProgram(data->shader_prog);
//	set_proj_matrix(data);
	set_variable(data);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, data->tex_refs[data->tex_nb]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_CUBE_MAP, data->tex_3d);
	//glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(data->vao);
	model_tmp = m4_rotation(data->rot_axis, data->rot_speed);
	data->model = m4_op(&model_tmp, '*', &data->model);
	m4_to_float(model_arr, &data->model, 1);
	m4_to_float(view_arr, &data->view, 1);
	modelLoc = glGetUniformLocation(data->shader_prog, "model");
	viewLoc  = glGetUniformLocation(data->shader_prog, "view");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model_arr);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view_arr);
	glDrawElements(GL_TRIANGLES, data->ebo_size, GL_UNSIGNED_INT, 0);//
	SDL_GL_SwapWindow(data->win->ptr);
}
