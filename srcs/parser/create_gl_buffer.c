/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_gl_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:23:59 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/04 13:59:52 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		create_gl_buffer(t_data *data, t_parse *parse)
{
	glEnable(GL_BLEND);//to use alpha
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // to use alpha
	//load_gl_texture(&data->tex_ref, "textures/Brick.tga");
	/*init buffer for vertices*/
	glGenVertexArrays(1, &data->vao);
	glGenBuffers(1, &data->vbo);
	glGenBuffers(1, &data->ebo);
	glBindVertexArray(data->vao);

	glBindBuffer(GL_ARRAY_BUFFER, data->vbo);
	glBufferData(GL_ARRAY_BUFFER, parse->vertex_buffer->size * sizeof(float),
			parse->vertex_buffer->buf, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			sizeof(int) * parse->vert_index->size,
			parse->vert_index->buf, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);
	data->ebo_size = (unsigned int)parse->vert_index->size; //* 3);
	printf("ebo_size = %u\n", data->ebo_size);
	return (1);
}
