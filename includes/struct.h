/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:54:28 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/01 14:16:51 by fchevrey         ###   ########.fr       */
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
	unsigned int	shader_prog;
	unsigned int	vbo;
	unsigned int	vao;
	unsigned int	ebo;
	unsigned int	tex_ref;
	t_4matrix		model;
	t_4matrix		view;
	t_4matrix		proj;
	t_vecfl			rot_axe;
}					t_data;

#endif
