/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:24:01 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/13 15:47:03 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "event.h"
#include "init.h"
#include "parser.h"

static int		init_gl_context(t_data *data, t_point size)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS,
			SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	data->win = wingl_new(size, "testgl");
	data->gl_ptr = SDL_GL_CreateContext(data->win->ptr);
	if (data->gl_ptr == 0)
	{
		ft_putendl(SDL_GetError());
		SDL_Quit();
		return (0);
	}
	SDL_GL_MakeCurrent(data->win->ptr, data->gl_ptr);
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		ft_putstr("Failed to initialize GLAD\n");
		return (0);
	}
	return (1);
}

static int		init_library(t_data *data)
{
	t_point		size;

	size = pt_set(WIN_WIDTH, WIN_HEIGHT);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putstr("Erreur lors de l'initialisation de la SDL : ");
		ft_putendl(SDL_GetError());
		SDL_Quit();
		return (-1);
	}
	return (init_gl_context(data, size));
}

static int		check_file_extension(char *filename)
{
	char	*dst;

	if (!(dst = ft_strrchr(filename, '.')))
		return (0);
	return (1);
}

static void		display_controls(void)
{
	ft_putendl("W : move up");
	ft_putendl("S : move down");
	ft_putendl("A : move left");
	ft_putendl("D : move right");
	ft_putendl("Q : move front");
	ft_putendl("E : move back");
	ft_putendl("X : rotate in x axis");
	ft_putendl("Y : rotate in y axis");
	ft_putendl("Z : rotate in z axis");
	ft_putendl("+ : rotation speed up");
	ft_putendl("- : rotation speed down");
	ft_putendl("M : change render mode");
	ft_putendl("P : change polygon mode");
	ft_putendl("T : change texture");
	ft_putendl("R : reload shaders");
	ft_putendl("I : reset position and rotation");
}

int				main(int ac, char **av)
{
	t_data		*data;

	if (ac != 2)
		return (ft_error("usage : ./scop filename", NULL, NULL));
	if (!check_file_extension(av[1]))
		return (ft_error("file extension error", NULL, NULL));
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (EXIT_FAILURE);
	if (!init_library(data))
		return (EXIT_FAILURE);
	if (!parse(data, av[1]))
		return (ft_error("file error", NULL, NULL));
	if (!init_data(data))
		return (EXIT_FAILURE);
	display_controls();
	main_loop(data);
	return (EXIT_SUCCESS);
}
