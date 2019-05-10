/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:25:35 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:19:23 by fchevrey         ###   ########.fr       */
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
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	ft_strdel(&frag_file);
	ft_strdel(&std_vert);
	return (shader_prog);
}

int						init_shaders(t_data *data)
{
	unsigned int		loc;

	data->shader_prog = init_prog_from_files(
			"shaders/f_scop.glsl", "shaders/v_scop.glsl");
	loc = glGetUniformLocation(data->shader_prog, "aIs_tex");
	glUniform1i(loc, 0);
	loc = glGetUniformLocation(data->shader_prog, "aIs_flat");
	glUniform1i(loc, 1);
	loc = glGetUniformLocation(data->shader_prog, "aIs_grey");
	glUniform1i(loc, 0);
	loc = glGetUniformLocation(data->shader_prog, "aIs_time");
	glUniform1i(loc, 0);
	loc = glGetUniformLocation(data->shader_prog, "aIs_3dtex");
	glUniform1i(loc, 0);
	loc = glGetUniformLocation(data->shader_prog, "aTime");
	glUniform1f(loc, 0.0f);
	glUseProgram(data->shader_prog);
	return (1);
}
