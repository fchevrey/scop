/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:33:52 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/13 16:56:01 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "tga.h"

int				init_data(t_data *data)
{
	data->timer = 0.0f;
	data->is_tex = 0;
	data->is_grey = 1;
	data->is_flat = 1;
	data->is_time = 0;
	data->is_3dtex = 0;
	data->is_dbtex = 0;
	if (!init_shaders(data))
	{
		ft_putendl("shader load error");
	}
	init_matrix(data);
	init_textures(data);
	return (1);
}
