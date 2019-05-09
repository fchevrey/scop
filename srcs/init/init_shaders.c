/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:25:35 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/09 15:45:19 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static unsigned int		init_prog_from_files(char *frag_filename,
		char *vert_filename)
{
	unsigned int			vert_shader;
	unsigned int			frag_shader;
	unsigned int			shader_prog;
	char					*frag_file;
	char					*std_vert;

	shader_prog = glCreateProgram();
	frag_file = load_shader(frag_filename);
	std_vert = load_shader(vert_filename);
	vert_shader = add_shader(std_vert, &shader_prog, GL_VERTEX_SHADER);
	frag_shader = add_shader(frag_file, &shader_prog, GL_FRAGMENT_SHADER);
	glLinkProgram(shader_prog);
//	glUseProgram(shader_prog);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	ft_strdel(&frag_file);
	ft_strdel(&std_vert);
	return (shader_prog);
}
/*
static void		add_frag_shader(char *frag_filename,
		unsigned int *shader_prog)
{
	unsigned int			frag_shader;
	char					*frag_file;

	frag_file = load_shader(frag_filename);
	frag_shader = add_shader(frag_file, shader_prog, GL_FRAGMENT_SHADER);
	glLinkProgram(*shader_prog);
//	glUseProgram(shader_prog);
	glDeleteShader(frag_shader);
	ft_strdel(&frag_file);
}
*/
/*static unsigned int		init_prog_from_v_ref(char *frag_filename,
		const unsigned int vert_shader)
{
	unsigned int			frag_shader;
	unsigned int			shader_prog;
	char					*frag_file;

	shader_prog = glCreateProgram();
	frag_file = load_shader(frag_filename);
	glAttachShader(shader_prog, vert_shader);
	frag_shader = add_shader(frag_file, &shader_prog, GL_FRAGMENT_SHADER);
	glLinkProgram(shader_prog);
	glUseProgram(shader_prog);
	glDeleteShader(frag_shader);
	ft_strdel(&frag_file);
	return (shader_prog);
}*/

int			init_shaders(t_data *data)
{
//	unsigned int			basic_v_shader;
//	char					*file_content;
	unsigned int		loc;

/*	file_content = load_shader("shaders/v_3d.glsl");
	basic_v_shader = add_shader(file_content, NULL, GL_VERTEX_SHADER);
	ft_strdel(&file_content);*/
	data->shader_prog = init_prog_from_files(
			"shaders/f_scop.glsl", "shaders/v_scop.glsl");
	loc = glGetUniformLocation(data->shader_prog, "aIs_tex");
	glUniform1i(loc, 0);
	loc = glGetUniformLocation(data->shader_prog, "aIs_flat");
	glUniform1i(loc, 0);
	loc = glGetUniformLocation(data->shader_prog, "aIs_grey");
	glUniform1i(loc, 0);
	loc = glGetUniformLocation(data->shader_prog, "aIs_time");
	glUniform1i(loc, 0);
	loc = glGetUniformLocation(data->shader_prog, "aTime");
	glUniform1f(loc, 0.0f);
/*	data->shader_prog[RENDER_MODE_RAINBOW] = init_prog_from_v_ref(
			"shaders/f_3d.glsl", basic_v_shader);
	data->shader_prog[RENDER_MODE_TEXTURE_FROM_POS] = init_prog_from_v_ref(
			"shaders/f_tex_from_pos.glsl", basic_v_shader);
	data->shader_prog[RENDER_MODE_TEXTURE_3D_FROM_POS] = init_prog_from_v_ref(
			"shaders/f_tex3d_from_pos.glsl", basic_v_shader);
	data->shader_prog[RENDER_MODE_UV] = init_prog_from_files(
			"shaders/f_3d_tex.glsl", "shaders/v_scop.glsl");*/
//	glDeleteShader(basic_v_shader);
	glUseProgram(data->shader_prog);
	return (1);
}
