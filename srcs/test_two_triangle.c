/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_two_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:52:33 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/10 18:24:53 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "init.h"

void			test_two_triangle(t_data *data)
{
	const unsigned int		nb_array = 2;
	unsigned int			shaderprogram_orange;
	unsigned int			shaderprogram_color;
	unsigned int			vert_shader;
	unsigned int			frag_shader;
	unsigned int			frag_shader_2;
	char					*orange;
	char					*purple;
	char					*std_vert;

	shaderprogram_orange = glCreateProgram();
	shaderprogram_color = glCreateProgram();
	orange = load_shader("shaders/orange.glsl");
	purple = load_shader("shaders/purple.glsl");
	std_vert = load_shader("shaders/std_vertex.glsl");
	ft_putendl("orange = ");
	ft_putendl(orange);
	ft_putendl("purple");
	ft_putendl(purple);
	ft_putendl("std vert = ");
	ft_putendl(std_vert);
	vert_shader = add_shader(std_vert, &shaderprogram_orange, GL_VERTEX_SHADER);
	frag_shader = add_shader(orange, &shaderprogram_orange, GL_FRAGMENT_SHADER);
	frag_shader_2 = add_shader(purple, &shaderprogram_color, GL_FRAGMENT_SHADER);
	glAttachShader(shaderprogram_color, vert_shader);
	glLinkProgram(shaderprogram_orange);
	glUseProgram(shaderprogram_orange);
	glLinkProgram(shaderprogram_color);
	glUseProgram(shaderprogram_color);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	glDeleteShader(frag_shader_2);
	ft_strdel(&orange);
	ft_strdel(&purple);
	ft_strdel(&std_vert);
	/*create vertices*/
	unsigned int		vbo[nb_array];//Vertex Buffer Object
	unsigned int		VAO[nb_array];//Vertex array Object
	float		vert[] = {
		-0.5f, -0.5f, 0.0f,//left
		0.5f, -0.5f, 0.0f,//right
			0.0f, 0.5f, 0.0f};//top
	float		vert2[] = {
		-0.2f, -0.2f, 0.0f,//left
		0.2f, -0.2f, 0.0f,//right
			0.0f, 0.2f, 0.0f};//top

	/*init buffer for vertices*/
	glGenVertexArrays(2, VAO);
	glGenBuffers(2, vbo);
	/*init first triangle*/
	glBindVertexArray(VAO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	/*init second triangle*/
	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert2), vert2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	while(!glfwWindowShouldClose(data->win))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		/*draw triangle one - orange*/
		glUseProgram(shaderprogram_orange);
		glBindVertexArray(VAO[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		/*draw triangle 2 violet*/
		glUseProgram(shaderprogram_color);
		glBindVertexArray(VAO[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(data->win);
		glfwPollEvents();
	}
	glDeleteVertexArrays(2, VAO);
	glDeleteBuffers(2, vbo);
	glfwTerminate();
}
