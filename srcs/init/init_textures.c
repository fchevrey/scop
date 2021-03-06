/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:08:09 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 18:39:32 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "tga.h"

static void				set_parameter(void)
{
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

static unsigned int		load_3d_tex(char *filename)
{
	t_texture		*txt;
	unsigned int	tex_nb;

	if (!(txt = ft_load_texture(filename)))
		return (0);
	glGenTextures(1, &tex_nb);
	glBindTexture(GL_TEXTURE_CUBE_MAP, tex_nb);
	set_parameter();
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
	free_tex(&txt);
	return (tex_nb);
}

int						init_textures(t_data *data)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (!load_gl_texture(&data->tex_refs[0], "textures/Brick.tga", 1))
		ft_putendl("brick load texture error");
	if (!load_gl_texture(&data->tex_refs[1], "textures/wood_container.tga", 1))
		ft_putendl("wood container texture load error");
	if (!load_gl_texture(&data->tex_refs[2], "textures/rainbow_unicorn.tga", 1))
		ft_putendl("rainbow_unicorn texture load error");
	if (!load_gl_texture(&data->tex_refs[3], "textures/skulls.tga", 1))
		ft_putendl("skull texture load error");
	if (!load_gl_texture(&data->tex_refs[4], "textures/smiley.tga", 0))
		ft_putendl("smiley texture load error");
	data->tex_3d = load_3d_tex("textures/brick_cube.tga");
	data->tex_nb = 0;
	return (1);
}
