/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:15:47 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 16:26:05 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmysdl.h"

t_win		*wingl_new(t_point size, char *title)
{
	t_win		*win;

	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (NULL);
	if (!(win->ptr = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, size.x, size.y,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
	{
		ft_putstr("SDL_CreateWindow error : ");
		ft_putendl(SDL_GetError());
		free(win);
		return (NULL);
	}
	win->ren = NULL;
	win->size = size;
	return (win);
}
