/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_two_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:52:33 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/10 15:59:20 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

const char *vertShaderSource = "#version 410 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char *fragShaderSource = "#version 410 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

const char *fragShaderSource2 = "#version 410 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 0.5f, 1.0f, 1.0f);\n"
"}\n\0";


unsigned int			add_shader(const char *shadersource, unsigned int *shaderprogram, int define)
{
	int					success;
	unsigned int		shader;
	char				infoLog[512];

	shader = glCreateShader(define);
	glShaderSource(shader, 1, &shadersource, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		ft_putstr("Shader compilation error :");
		ft_putendl(infoLog);
		return 0;
	}
	if (shaderprogram)
		glAttachShader(*shaderprogram, shader);
	return shader;
}

void			test_two_triangle(t_data *data)
{
	const unsigned int		nb_array = 2;
	unsigned int			shaderprogram_orange;
	unsigned int			shaderprogram_color;
	unsigned int			vert_shader;
	unsigned int			frag_shader;
	unsigned int			frag_shader_2;

	shaderprogram_orange = glCreateProgram();
	shaderprogram_color = glCreateProgram();
	vert_shader = add_shader(vertShaderSource, &shaderprogram_orange, GL_VERTEX_SHADER);
	frag_shader = add_shader(fragShaderSource, &shaderprogram_orange, GL_FRAGMENT_SHADER);
	frag_shader_2 = add_shader(fragShaderSource2, &shaderprogram_color, GL_FRAGMENT_SHADER);
	glAttachShader(shaderprogram_color, vert_shader);
	glLinkProgram(shaderprogram_orange);
	glUseProgram(shaderprogram_orange);
	glLinkProgram(shaderprogram_color);
	glUseProgram(shaderprogram_color);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	glDeleteShader(frag_shader_2);
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
