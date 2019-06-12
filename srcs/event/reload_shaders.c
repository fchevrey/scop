/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:24:32 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/13 16:55:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "init.h"

void		reload_shaders(t_data *data)
{
	int		i;

	i = 0;
	while (i < SHADER_PROG_SIZE)
	{
		glDeleteProgram(data->progs[i]);
		i++;
	}
	if (!init_shaders(data))
	{
		ft_putendl("shader load error");
	}
}
