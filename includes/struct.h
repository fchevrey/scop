/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:54:28 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 15:48:54 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "scop.h"

typedef union			u_color
{
	uint32_t			c;
	struct				s_argb
	{
		uint8_t			b;
		uint8_t			g;
		uint8_t			r;
		uint8_t			a;
	}					argb;
}						t_color;

typedef struct		s_data
{
	t_win			*win;
	SDL_GLContext	gl_ptr;
	unsigned int	shader_prog[RENDER_MODE_SIZE];
	unsigned int	vbo;
	unsigned int	vao;
	unsigned int	ebo;
	unsigned int	tex_ref;
	unsigned int	ebo_size;
	short			is_texture;
	short			is_normal;
	int				render_mode;
	t_4matrix		model;
	t_4matrix		view;
	t_4matrix		proj;
	t_vecfl			rot_axis;
	float			rot_speed;
}					t_data;

#endif
