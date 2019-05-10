/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:19:15 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 18:37:34 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

/*
** the max used is TEXTURE_MAX -1 because the last texture is only used
** for the 2textures blend mode
*/

void		change_texture(t_data *data)
{
	data->tex_nb++;
	if (data->tex_nb >= TEXTURE_MAX - 1)
		data->tex_nb = 0;
}
