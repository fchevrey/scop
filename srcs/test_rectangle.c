/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:39:17 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/23 16:24:39 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "init.h"

void			test_rectangle(t_data *data)
{
	const unsigned int		nb_array = 2;
	unsigned int			shaderprogram_orange;
	unsigned int			vert_shader;
	unsigned int			frag_shader;
	char					*orange;
	char					*purple;
	char					*std_vert;


	shaderprogram_orange = glCreateProgram();
	orange = load_shader("shaders/orange.glsl");
	purple = load_shader("shaders/purple.glsl");
	std_vert = load_shader("shaders/std_vertex.glsl");
	vert_shader = add_shader(std_vert, &shaderprogram_orange, GL_VERTEX_SHADER);
	frag_shader = add_shader(orange, &shaderprogram_orange, GL_FRAGMENT_SHADER);
	glLinkProgram(shaderprogram_orange);
	glUseProgram(shaderprogram_orange);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	ft_strdel(&orange);
	ft_strdel(&std_vert);
	/*create vertices*/
	unsigned int		vbo;//Vertex Buffer Object
	unsigned int		VAO;//Vertex array Object
	float		vert[] = {
		0.5f, 0.5f, 0.0f,//top right
		0.5f, -0.5f, 0.0f,//bottom rigth
			-0.5f, -0.5f, 0.0f,//top
			-0.5f, 0.5f, 0.0f};//top
	unsigned int		indices[] =
	{
		0, 1, 3,
		1, 2, 3
	};
	unsigned int		ebo;//Element Buffer Array used to stock indices

	/*init buffer for vertices*/
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(VAO);
	/*init triangle*/
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	/*init buffer for indices*/
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	while(!glfwWindowShouldClose(data->win))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderprogram_orange);
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(data->win);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glfwTerminate();
}
