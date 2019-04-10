/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:39:17 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/10 17:17:21 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"


/*const char *fragShaderSource2 = "#version 410 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 0.5f, 1.0f, 1.0f);\n"
"}\n\0";*/

/*void		framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}*/

/*static int		init_library(t_data *data, int *ac, char **av)
{
	t_point		size;

	size = pt_set(WIN_WIDTH, WIN_HEIGHT);
	if (!glfwInit())
		return  ft_error("GLWl init failed", NULL, NULL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//GLFWwindow		*win;
	data->win = glfwCreateWindow(size.x, size.y, "LearnOPenGL", NULL, NULL);
	if (!data->win)
		return ft_error("window wont open", NULL, NULL);
	glfwMakeContextCurrent(data->win);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putstr("Failed to initialize GLAD\n");
		return -1;
	}
	glfwSetFramebufferSizeCallback(data->win, &framebuffer_size_callback);
	return (1);
}*/

static unsigned int			add_shader(const char *shadersource, unsigned int *shaderprogram, int define)
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
	glAttachShader(*shaderprogram, shader);
	return shader;
}

void			test_rectangle(t_data *data)
{
const char *verteShaderSource = "#version 410 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char *fragmShaderSource = "#version 410 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
	const unsigned int		nb_array = 2;
	unsigned int			shaderprogram_orange;
	unsigned int			vert_shader;
	unsigned int			frag_shader;

	shaderprogram_orange = glCreateProgram();
	vert_shader = add_shader(verteShaderSource, &shaderprogram_orange, GL_VERTEX_SHADER);
	frag_shader = add_shader(fragmShaderSource, &shaderprogram_orange, GL_FRAGMENT_SHADER);
	glLinkProgram(shaderprogram_orange);
	glUseProgram(shaderprogram_orange);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
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
