#include "scop.h"

static int		init_library(t_data *data)
{
	t_point		size;

	size = pt_set(WIN_WIDTH, WIN_HEIGHT);
	if (SDL_Init(SDL_INIT_VIDEO))
		return (ft_error("SDL_init error :", SDL_GetError(), NULL));
	data->win = win_new(size, "Scop");
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
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
	if (!init_library(data))
		return (EXIT_SUCCESS);
	ft_exit(&data);
	return (EXIT_SUCCESS);
}
