/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:19:15 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 18:21:49 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void		change_texture(t_data *data)
{
	data->tex_nb++;
	if (data->tex_nb >= TEXTURE_MAX)
		data->tex_nb = 0;
}
