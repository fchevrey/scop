/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:25:35 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/13 16:54:27 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static int		init_prog_from_files(char *frag_filename,
		char *vert_filename, unsigned int *shader_prog)
{
	unsigned int			vert_shader;
	unsigned int			frag_shader;
	char					*frag_file;
	char					*std_vert;

	*shader_prog = glCreateProgram();
	if (!(frag_file = load_shader(frag_filename)))
		return (0);
	if (!(std_vert = load_shader(vert_filename)))
		return (0);
	vert_shader = add_shader(std_vert, shader_prog, GL_VERTEX_SHADER);
	frag_shader = add_shader(frag_file, shader_prog, GL_FRAGMENT_SHADER);
	glLinkProgram(*shader_prog);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	ft_strdel(&frag_file);
	ft_strdel(&std_vert);
	return (1);
}

int						init_shaders(t_data *data)
{
	if (!init_prog_from_files("shaders/f_scop.glsl", "shaders/v_scop.glsl",
			 &data->progs[0]))
		return (0);
	if (!init_prog_from_files("shaders/f_tex3d_from_pos.glsl",
			"shaders/v_3d_tex.glsl", &data->progs[1]))
		return (0);
	data->shader_prog = data->progs[0];
	glUseProgram(data->shader_prog);
	return (1);
}
