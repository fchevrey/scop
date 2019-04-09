/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:10:26 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/09 21:32:02 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scop.h"

void		ft_exit(t_data **data)
{
	ft_putendl("quitting...");
	if (!data || !*data)
		exit(EXIT_SUCCESS);
	//SDL_GL_DeleteContext((*data)->gl_ptr);
	//free_win(&(*data)->win);
	free(*data);
	*data = NULL;
	//SDL_Quit();
	exit(EXIT_SUCCESS);
}
