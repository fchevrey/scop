/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:10:26 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/29 19:05:45 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scop.h"

void		ft_exit(t_data **data)
{
	ft_putendl("quitting...");
	if (!data || !*data)
		exit(EXIT_SUCCESS);
	glDeleteVertexArrays(1, &(*data)->vao);
	glDeleteBuffers(1, &(*data)->vbo);
	glDeleteBuffers(1, &(*data)->ebo);
	SDL_GL_DeleteContext((*data)->gl_ptr);
	free_win(&(*data)->win);
	SDL_Quit();
	free(*data);
	*data = NULL;
	exit(EXIT_SUCCESS);
}
