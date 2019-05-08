/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_new_no_sdl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:26:26 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/08 13:27:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_texture	*texture_new_no_sdl(t_point size)
{
	t_texture			*tex;

	if ((tex = (t_texture*)malloc(sizeof(t_texture))) == NULL)
		return (NULL);
	if (!(tex->tab_pxl = (uint32_t*)malloc(sizeof(uint32_t) * size.x * size.y)))
		return (NULL);
	tex->size.x = size.x;
	tex->size.y = size.y;
	tex->sdl_tex = NULL;
	return (tex);
}
