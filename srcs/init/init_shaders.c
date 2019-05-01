/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:25:35 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/01 14:48:37 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int			init_shaders(t_data *data)
{
	unsigned int			vert_shader;
	unsigned int			frag_shader;
	char					*frag_file;
	char					*std_vert;

	data->shader_prog = glCreateProgram();
	frag_file = load_shader("shaders/f_3d_tex.glsl");
	std_vert = load_shader("shaders/v_3d_tex.glsl");
	vert_shader = add_shader(std_vert, &data->shader_prog, GL_VERTEX_SHADER);
	frag_shader = add_shader(frag_file, &data->shader_prog, GL_FRAGMENT_SHADER);
	glLinkProgram(data->shader_prog);
	glUseProgram(data->shader_prog);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	ft_strdel(&frag_file);
	ft_strdel(&std_vert);
	return (1);
}
