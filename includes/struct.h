/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:54:28 by fchevrey          #+#    #+#             */
/*   Updated: 2019/03/19 16:28:23 by fchevrey         ###   ########.fr       */
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
}					t_data;

#endif
