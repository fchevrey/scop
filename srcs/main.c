/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:24:01 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/10 18:38:18 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "event.h"
#include "init.h"
const char *vertexShaderSource = "#version 410 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char *fragmentShaderSource = "#version 410 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

void		framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

static int		init_library(t_data *data, int *ac, char **av)
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
}
void			test_vertices(t_data *data)
{
	int					success;
	/*create shader*/
	unsigned int	vertexShader;
	char			infoLog[512];
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		ft_putstr("Shader compilation error :");
		ft_putendl(infoLog);
		return ;
	}
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		ft_putstr("Shader compilation error :");
		ft_putendl(infoLog);
		return ;
	}
	/*create program shader*/
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success) 
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		ft_putstr("Shader Program error :");
		ft_putendl(infoLog);
	}
	glUseProgram(shaderProgram);
	/* Destroy useless shaders */
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	/*create vertices*/
	unsigned int		vbo;//Vertex Buffer Object
	unsigned int		VAO;//Vertex array Object
	float		vert[] = {
		-0.5f, -0.5f, 0.0f,//left
		0.5f, -0.5f, 0.0f,//right
			0.0f, 0.5f, 0.0f};//top

	/*init buffer for vertices*/
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vbo);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); 
	//first parametter is 0 because location = 0 in first shaders
	//second is 3 because we pass vector
	//Flase because we don't want normalized values
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	/*Create VAO*/
	glDrawArrays(GL_TRIANGLES, 0, 3);
	/*glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vert);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);*/
	while(!glfwWindowShouldClose(data->win))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(data->win);
		glfwPollEvents();
	}
	//test_vertices(data);
	//main_loop(data);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &vbo);
	glfwTerminate();
}

int				main(int ac, char **av)
{
	t_data		*data;

	if (ac != 2)
		return (ft_error("usage : ./scop filename", NULL, NULL));
	//	if (!av || !av[1] || !parse(av[1]))
	//		ft_error("error while reading file", NULL, NULL);
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (EXIT_SUCCESS);
	if (!init_library(data, &ac, av))
		return (EXIT_SUCCESS);
	///glEnable(GL_DEPTH_TEST);
		//test_vertices(data);
	//	test_rectangle(data);
		test_two_triangle(data);
	//ft_exit(&data);
	return (EXIT_SUCCESS);
}
