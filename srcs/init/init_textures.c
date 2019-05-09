/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:08:09 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/09 12:01:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "tga.h"

unsigned int	load_3d_tex(char *filename)
{
	t_texture		*txt;
	unsigned int	tex_nb;

	if (!(txt = ft_load_texture(filename)))
		return (0);
	glGenTextures(1, &tex_nb);
	glBindTexture(GL_TEXTURE_CUBE_MAP, tex_nb);
	// définit les options de la texture actuellement liée
	/*glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);*/
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, txt->size.x,
			txt->size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, txt->size.x,
			txt->size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, txt->size.x,
			txt->size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, txt->size.x,
			txt->size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, txt->size.x,
			txt->size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, txt->size.x,
			txt->size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_BGRA, txt->size.x, txt->size.y,
	//	0, GL_BGRA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	//glGenerateMipmap(GL_TEXTURE_2D);
	free_tex(&txt);
	return (1);
}

int				init_textures(t_data *data)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (!load_gl_texture(&data->tex_refs[0], "textures/Brick.tga"))
	{
		ft_putendl("brick load error");
	}
	if (!load_gl_texture(&data->tex_refs[1], "textures/wood_container.tga"))
	{
		ft_putendl("container load error");
	}
	if (!load_gl_texture(&data->tex_refs[2], "textures/rainbow_unicorn.tga"))
		//	if (!load_gl_texture(&data->tex_refs[2], "textures/smiley.tga"))
	{
		ft_putendl("smiley load error");
	}
	//	if (!load_gl_texture(&data->tex_refs[3], "textures/rainbow_unicorn.tga"))
	if (!load_gl_texture(&data->tex_refs[3], "textures/skulls.tga"))
	{
		ft_putendl("rainbow_unicorn load error");
	}
	data->tex_3d = load_3d_tex("textures/brick_cube.tga");
	data->tex_nb = 4;
	return (1);
}
