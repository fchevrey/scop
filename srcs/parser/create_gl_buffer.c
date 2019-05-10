/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_gl_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:23:59 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 19:09:25 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "tga.h"

static void		cpy_buf(float *dst, float *src, size_t len, t_parse *parse)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < (len - 3))
	{
		dst[i + 0] = src[j];
		dst[i + 1] = src[j + 1];
		dst[i + 2] = src[j + 2];
		dst[i + 3] = src[j] / parse->center.x;
		dst[i + 4] = src[j + 1] / parse->center.y;
		dst[i + 5] = src[j + 2] / parse->center.z;
		i += 6;
		j += 3;
	}
}

static int		create_vao(t_data *data, t_parse *parse)
{
	float			*buffer;
	size_t			size_vert;

	glGenVertexArrays(1, &data->vao);
	glBindVertexArray(data->vao);
	glGenBuffers(1, &data->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, data->vbo);
	size_vert = (sizeof(float)) * parse->vertex_buffer->size * 2;
	buffer = (float*)malloc(size_vert);
	cpy_buf(buffer, parse->vertex_buffer->buf,
			parse->vertex_buffer->size * 2, parse);
	glBufferData(GL_ARRAY_BUFFER, size_vert,
			buffer, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
			(void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
			(void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(0);
	free(buffer);
	buffer = NULL;
	return (1);
}

int				create_gl_buffer(t_data *data, t_parse *parse)
{
	if (!parse->vertex_buffer->buf || !parse->vert_index->buf)
		return (0);
	glGenBuffers(1, &data->ebo);
	create_vao(data, parse);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			sizeof(int) * parse->vert_index->size,
			parse->vert_index->buf + parse->tex_index->size, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);
	data->ebo_size = (unsigned int)parse->vert_index->size;
	data->is_texture = parse->is_texture;
	data->is_normal = parse->is_normal;
	return (1);
}
