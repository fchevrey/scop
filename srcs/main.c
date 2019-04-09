/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:24:01 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/09 18:53:00 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "event.h"

t_win		*wingl_new(t_point size, char *title)
{
	t_win		*win;

	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (NULL);
	if (!(win->ptr = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, \
					SDL_WINDOWPOS_CENTERED, size.x, size.y, 0)))
	{
		ft_putstr("SDL_CreateWindow error : ");
		ft_putendl(SDL_GetError());
		free(win);
		return (NULL);
	}
	ft_putstr("pouet");
	//SDL_MaximizeWindow(win->ptr);
	//SDL_RestoreWindow(win->ptr);
	win->ren = NULL;
	win->size = size;
	return (win);
}
void	myDisplayFunc() 
{
	// gfx fun
}

static int		init_library(t_data *data, int *ac, char **av)
{
	t_point		size;

	size = pt_set(WIN_WIDTH, WIN_HEIGHT);
	//	if (SDL_Init(SDL_INIT_VIDEO))
	//		return (ft_error("SDL_init error :", SDL_GetError(), NULL));
	//data->win = wingl_new(size, "Scop");
	/*SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);*/
	//glewExperimental = GL_TRUE;
	ft_putstr("A\n");
	//glewInit();
	ft_putstr("B\n");
	if (!glfwInit())
		return  ft_error("GLWl init failed", NULL, NULL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//if (!(data->gl_ptr = SDL_GL_CreateContext(data->win->ptr)))
	//	return (ft_error(SDL_GetError(), NULL, NULL));
	return (1);
}
void displayMe(void)
{
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glEnd();
}

void			test_vertices(t_data *data)
{
	//t_ptfl		vertices[3];
	GLfloat		vert[] = {1.0, 1.0, 0.0, 0.0, 0.5, 0.5};

	/*vertices[0] = ptfl_set(-0.5, -0.5);
	  vertices[1] = ptfl_set(0.0, 0.5);
	  vertices[2] = ptfl_set(0.5, -0.5);*/
	ft_putstr("1\n");
	glViewport(0, 0, 800, 600);
	ft_putstr("2\n");
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vert);
	ft_putstr("3\n");
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
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
	ft_putstr("a\n");
	GLFWwindow		*win;
	win = glfwCreateWindow(800, 600, "LearnOPenGL", NULL, NULL);
	ft_putstr("b\n");
	if (!win)
		return ft_error("window wont open", NULL, NULL);
	ft_putstr("c\n");
	glfwMakeContextCurrent(win);
	glEnable(GL_DEPTH_TEST);
	while(!glfwWindowShouldClose(win))
	{
		test_vertices(data);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		displayMe();
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	ft_putstr("d\n");
	//test_vertices(data);
	//main_loop(data);
	glfwTerminate();
	//ft_exit(&data);
	return (EXIT_SUCCESS);
}
