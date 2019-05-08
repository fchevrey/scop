/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_gl_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:23:59 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/08 18:56:29 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "tga.h"

static void		cpy_buf(float *src, float *dst, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		src[i] = dst[i];
		i++;
	}
}

static int		create_vao(t_data *data, t_parse *parse)
{
	//unsigned char	*buffer;
	float			*buffer;
	size_t			size_vert;
	size_t			size_uv;

	glGenVertexArrays(1, &data->vao);
	glBindVertexArray(data->vao);
	size_vert = (sizeof(float))  * parse->vertex_buffer->size;
	printf("size_vert = %zu", size_vert);
	printf("  bufsize = %zu\n", parse->vertex_buffer->size);
	size_uv = sizeof(float) * parse->tex_buffer->size;
	buffer = (float*)malloc(size_vert + size_uv);
	//ft_memcpy(buffer,parse->vertex_buffer->buf, size_vert);
	//ft_memcpy(buffer + size_vert, parse->tex_index, size_uv);
	cpy_buf(buffer, parse->vertex_buffer->buf, parse->vertex_buffer->size);
	cpy_buf(&buffer[parse->vertex_buffer->size], parse->tex_buffer->buf,
			parse->tex_buffer->size);
	glBufferData(GL_ARRAY_BUFFER, parse->vertex_buffer->size * sizeof(float),
			buffer, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0,
			buffer + parse->vertex_buffer->size);
	size_uv = parse->vertex_buffer->size;
	float *buf2;
	buf2 = buffer + size_uv;
	printf("buf 4 v :[ %f, %f, %f, %f]\n", buf2[0], buf2[1], buf2[2], buf2[3]);
	glEnableVertexAttribArray(1);
/*	glGenVertexArrays(1, &data->vao);
	glBindVertexArray(data->vao);
	glBufferData(GL_ARRAY_BUFFER, parse->vertex_buffer->size * sizeof(float),
			parse->vertex_buffer->buf, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_UNSIGNED_INT, GL_FALSE, 2 * sizeof(unsigned int),
			parse->tex_index->buf);
	glEnableVertexAttribArray(1);*/
	return (1);
}

int				create_gl_buffer(t_data *data, t_parse *parse)
{
	glGenBuffers(1, &data->ebo);
	glGenBuffers(1, &data->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, data->vbo);
	create_vao(data, parse);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			sizeof(int) * parse->vert_index->size,
			parse->vert_index->buf + parse->tex_index->size, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);
	data->ebo_size = (unsigned int)parse->vert_index->size;
	data->render_mode = RENDER_MODE_RAINBOW;
	data->is_texture = (short)parse->is_texture;
	data->is_normal = (short)parse->is_normal;
	return (1);
}
