/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:24:01 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/23 14:59:44 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "event.h"
#include "init.h"

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
		test_texts(data);
//		test_two_triangle(data);
	//ft_exit(&data);
	return (EXIT_SUCCESS);
}
