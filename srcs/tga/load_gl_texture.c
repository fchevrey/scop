/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_gl_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:40:10 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/08 13:23:24 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tga.h"

int				load_gl_texture(unsigned int *text_number, char *filename)
{
	t_texture	*txt;

	if (!(txt = ft_load_texture(filename)))
		return (0);
	glGenTextures(1, text_number);
	glBindTexture(GL_TEXTURE_2D, *text_number);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, txt->size.x, txt->size.y, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	glGenerateMipmap(GL_TEXTURE_2D);
	free_tex(&txt);
	return (1);
}
